
#include <iostream>
#include "Stackt.h"
using namespace std; 

int main()
{
    string infix_string;// Declare variables to hold the input infix string and the output postfix string
    string postfix_string = "";
    // Declare two stacks: one for infix expression one for postfix expression
    Stackt<char> infix; 
    Stackt<double> postfix;
    int i = 0; 
    int j = 0;


    cout<<"enter the infix string: \n";
    cin>>infix_string; 
    // Initialize character pointers to navigate through strings
    char *p = &infix_string[0];
    char *q = &postfix_string[0];

    while (i < infix_string.length())
    {
        if ((*p=='(') || (*p =='+') || (*p=='-'))// If the character is an opening parenthesis or + or -
        {
            infix.push(*p); // Push it onto the infix stack and move to the next character
            p++;
        }

        else if ((*p == '*') || (*p == '/')) // If the character is a * or /
        {
            // Pop from infix stack to postfix_string while top of stack is * or /
            while (!infix.is_empty() && (infix.top_element() == '*' || infix.top_element() == '/'))
            {
                postfix_string = postfix_string + infix.top_element();
                infix.pop();
            }

            infix.push(*p); // Push the current operator onto the stack
            p++;
        }

        else if((*p==')'))  // If the character is a closing parenthesis
        {
            while (!infix.is_empty() && infix.top_element() != '(') // Pop from the infix stack to postfix_string until an opening parenthesis is found
            {
                postfix_string = postfix_string + infix.top_element(); 
                infix.pop();
            }
            infix.pop(); // Pop the opening parenthesis from the stack but don't add it to postfix_string
            p++; 
        }

        else// If the character is an number
        {
            postfix_string = postfix_string + *p;  // put the number in the postfix string
            p++;
        }

        i++; // Move to the next character in the infix string
    }

    // After processing the entire infix string, pop any remaining operators from the stack to postfix_string
    if (!infix.is_empty())
   
        postfix_string = postfix_string + infix.top_element();

    while (j < postfix_string.length())
     {
        if ((*q != '+') && (*q != '-') && (*q != '*') && (*q != '/'))// If the character is an operand
            {
                postfix.push(*q - '0');  // Convert the character to its numeric value and push onto the postfix stack
                q++;
            }
            else// If the character is an operator
            {
                double temp;
                double v1;
                double v2;

                // Pop two operands from the postfix stack
                v1 = postfix.top_element();
                postfix.pop();

                v2 = postfix.top_element();
                postfix.pop();
                // Perform the corresponding operation based on the operator
                if (*q == '+')
                    temp = v2 + v1;

                else if (*q == '-')
                    temp = v2 - v1;

                else if (*q == '*')
                    temp = v2 * v1;

                else if (*q == '/')
                    temp = v2 / v1;

                postfix.push(temp);// Push the result back onto the postfix stack
                q++;
            }

            j++;// Move to the next character in the postfix string
         }

    //output results
    cout<<"The infix strting is: "<<infix_string<<endl;
    cout<<"The postfix string is "<<postfix_string<<endl;
    cout<<"The result of the postfix calculation is "<<postfix.top_element()<<endl;
}
