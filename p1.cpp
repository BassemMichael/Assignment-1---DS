
#include <iostream>
#include <stack>
using namespace std;

void print_stack(stack<int> x) //to print the contents of the source and target stacks
{
    while (!x.empty()) {
        cout << x.top() << " "; // Print the top element of the stack
        x.pop();// Remove the top element
    }
    cout << endl;
}

void Towers(int N, stack<int> &source, stack<int> &aux, stack<int> &target)
{
    if (N == 1) // Base case: if only one disk, simply move it from source to target
    {
        target.push(source.top());// Move the top disk from source to target
        source.pop();   // Remove the top disk from the source stack
    }
    else // Recursive case: move N-1 disks, then the Nth disk, and then N-1 disks again
    {
        Towers(N - 1, source, target, aux);// Move top N-1 disks from source to auxiliary, using target as a temporary stack

        target.push(source.top()); // Move the remaining disk from source to target
        source.pop();

        Towers(N - 1, aux, source, target);// Move the N-1 disks from auxiliary to target, using source as a temporary stack
    }
}

int main()
{
    int N;
    stack<int> source; 
    stack<int> aux; 
    stack<int> target; 
    


    cout<<"Please enter the number of disks: "<<endl;
    cin>> N;

    for(int i = N; i>0; i--) // Initialize the source stack with disks, largest at the bottom
    {
        source.push(i);// Push disks onto the source stack in decreasing order
    }



    cout << "Initial state of the source stack: ";// Print the initial state of the source stack
    print_stack(source);

    

    Towers(N, source, aux, target); // Call the Towers function to move all disks from source to target

    cout << "State of the source stack after Towers function: ";// Print the state of the source stack after the Towers function 
    print_stack(source);
    cout << "State of the target stack after Towers function: ";// Print the state of the target stack 
    print_stack(target);
}

