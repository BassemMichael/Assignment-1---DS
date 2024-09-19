
#include <iostream>
using namespace std; 

template <typename p>// Template class for a stack data structure

class Stackt
{
    private: 
        p *stack; // Pointer to the stack array
        int top; // Index of the top element in the stack
        int capacity; // Capacity of the stack (size of the array)
    public:
        Stackt()// Default constructor
        {
            stack = nullptr; // Initialize stack pointer to null
            top = -1; // Initial top index (stack is empty)
            capacity = 0; // Initial capacity of the stack
        }

        Stackt(Stackt *copy)        // Copy constructor
        {
            top = copy->top; // Copy top index
            capacity = copy->capacity; // Copy capacity
            stack = new p[capacity]; // Allocate new stack array
        // Copy elements from the original stack
            for (int i = 0; i<=top; i++)
                stack[i] = copy[i];
        }

        void push(p element)// Push an element onto the stack
        {
            if (capacity == 0)// If the stack is empty, initialize it with a capacity of 1
            {
                capacity = 1;
                stack = new p[capacity];
            }

            else if (top == capacity-1)// If the stack is full, increase its capacity
            {
                capacity++; 
                p* new_stack = new p[capacity];// Create a new stack with increased capacity 

                for (int i = 0; i<=top; i++) // Copy existing elements to the new stack
                    new_stack[i] = stack[i];

                stack = new_stack; 
            }

            stack[++top] = element; // Push the new element onto the stack and increment the top index

        }

        p pop()// Pop an element from the stack
        {
            return stack[top--];// Return the top element and decrement the top index
        }
        
        bool is_empty()        // Check if the stack is empty

        {
            if (top == -1)// Return true if top index is -1, indicating an empty stack
                return true;

            else 
                return false;  
        }

        p top_element()// Get the top element of the stack
        {
            return stack[top]; // Return the top element
        }

        Stackt& operator=(const Stackt& other) {
        if (this != &other) {  // Prevent self-assignment
            delete[] stack;      // Release the current memory
         capacity = other.capacity;
        top = other.top;
        arr = new p[capacity]; // Allocate new memory for the copy

        // Copy elements from the other stack
        for (int i = 0; i <= top; i++) {
            stack[i] = other.arr[i];
        }
        return *this;
        }
    
    }

}; 

