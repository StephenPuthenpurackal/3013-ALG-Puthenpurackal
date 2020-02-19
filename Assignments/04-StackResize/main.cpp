///////////////////////////////////////////////////////////////////////////////
//
// Author:           Stephen
// Email:            sjputhenpurack1225@my.msutexas.edu
// Label:            04-P01
// Title:            Assignment 4 - Resizing the Stack
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//       Overview of a class implementing an array based stack
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/**
 * ArrayStack
 * 
 * Description:
 *      Array based stack
 * 
 * Public Methods:
 *      - See class below
 * 
 * Usage: 
 *      - See main program
 *      
 */
class ArrayStack
{
private:
    int *A;   // pointer to array of int's
    int size; // current max stack size
    int top;  // top of stack
    int resizeCount; // The number of times the stack has been resized in any kind of way;
    int SizeMax; //  Maximum size that has been reached thus far, but the stack

public:
    /**
  * ArrayStack
  * 
  * Description:
  *      Constructor no params
  * 
  * Params:
  *     - None
  * 
  * Returns:
  *     - NULL
  */
    ArrayStack()
    {
        size = SizeMax = 10;
        A = new int[size];
        top = -1;
        resizeCount = 0;
    }

    /**
  * ArrayStack
  * 
  * Description:
  *      Constructor size param
  * 
  * Params:
  *     - int size
  * 
  * Returns:
  *     - NULL
  */
    ArrayStack(int s)
    {
        size = SizeMax = s;
        A = new int[s];
        top = -1;
        resizeCount = 0;
    }

    /**
  * Public bool: Empty
  * 
  * Description:
  *      Stack empty?
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [bool] true = empty
  */
    bool Empty()
    {
        return (top <= -1);
    }

    /**
  * Public bool: Full
  * 
  * Description:
  *      Stack full?
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [bool] true = full
  */
    bool Full()
    {
        return (top >= size - 1);
    }

    /**
  * Public int: Peek
  * 
  * Description:
  *      Returns top value without altering the stack
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [int] top value if any
  */
    int Peek()
    {
        if (!Empty())
        {
            return A[top];
        }

        return -99; // some sentinel value
                    // not a good solution
    }

    /**
  * Public int: Pop
  * 
  * Description:
  *      Returns top value and removes it from stack
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [int] top value if any
  */
    int Pop()
    {
        if (!Empty())
        {   
            int Temp;
            Temp = A[top--];
            
            // Since the size of the stack cannot falter below 10, with proper indexing of the ratio we use 19 as a comparison sentinal. 
            //  

            if((((top+1) >= (size/2)) == false) && (size > 19)){
                    ContainerShrink();
              }
            // if(!((top + 1) >= (size/2)) && (size > 19)){
            //     ContainerShrink();
            // }

            return Temp;
        }

        return -99; // some sentinel value
                    // not a good solution
    }

    /**
  * Public void: Print
  * 
  * Description:
  *      Prints stack to standard out
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
    void Print(ifstream& infile, ofstream& outfile)
    {
        for (int i = 0; i <= top; i++)
        {
            //cout<<A[i]<<" ";
            outfile << A[i] << endl;
        }
        outfile << endl;
    }

    /**
  * Public bool: Push
  * 
  * Description:
  *      Adds an item to top of stack
  * 
  * Params:
  *      [int] : item to be added
  * 
  * Returns:
  *      [bool] ; success = true
  */
    bool Push(int x)
    {
        if (Full())
        {
            ContainerGrow();
        }
        if (!Full())
        {
            A[++top] = x;
            return true;
        }

        return false;
    }

    /**
  * Public void: Resize
  * 
  * Description:
  *      Resizes the container for the stack by doubling
  *      its capacity
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
    void Resize()
    {
        int newSize = size * 2;    // double size of original
        int *B = new int[newSize]; // allocate new memory

        for (int i = 0; i < size; i++)
        { // copy values to new array
            B[i] = A[i];
        }

        delete[] A; // delete old array

        size = newSize; // save new size
        SizeMax = size;

        A = B; // reset array pointer
    }

    void ContainerGrow()
    {
        int newSize = size * 1.75;    // double size of original
        int *B = new int[newSize]; // allocate new memory

        for (int i = 0; i < newSize; i++)
        { // copy values to new array
            B[i] = A[i];
        }

        delete[] A; // delete old array

        size = newSize; // save new size
        SizeMax = size;

        A = B; // reset array pointer

        resizeCount++;
    }

    void ContainerShrink()
    {
         int newSize = size -0.5;    // double size of original
        int *B = new int[newSize]; // allocate new memory

        for (int i = 0; i < newSize; i++)
        { // copy values to new array
            B[i] = A[i];
        }

        delete[] A; // delete old array

        size = newSize; // save new size

        A = B; // reset array pointer

        resizeCount++;
    }

    void CheckResize(ArrayStack stack)
    {
        cout << "CheckSize" << endl;
        return;
    }
};

// MAIN DRIVER
// Simple Array Based Stack Usage:
int main()
{
    int x = 0;
    ifstream infile;
    infile.open("nums.dat");
    ofstream outfile;
    outfile.open("output.txt");
    ArrayStack stack;



    while (!infile.eof())
    {
        infile >> x;
        // Modulus operator returns the remainder of the divisible.
        // If remainder is equal to zero,
        // then we know that the answer is even
        if (x % 2 == 0)
        {   

            // Short version to check whether if the push is available, 
            // and if available, then push() is already executed
             if(!stack.Push(x))
            {
                cout << "Push failed" << endl;
            }
            // else{
                cout << "Push happened " << endl;
            //     }
        } 

        // Every other number will be odd
        stack.Pop();
        cout << "Stack is popping " << endl;

    }
    cout << "Printing Stack" << endl;
    stack.Print(infile,outfile);


    return 0;
}