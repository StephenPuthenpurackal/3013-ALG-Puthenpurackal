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
    int resizeCount;

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
        size = 10;
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
        size = s;
        A = new int[s];
        top = -1;
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
            return A[top--];
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
    void Print()
    {
        for (int i = 0; i <= top; i++)
        {
            //cout<<A[i]<<" ";
            cout << A[i] << endl;
            ;
        }
        cout << endl;
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
            resizeCount++;
        }
        if (!Full())
        {
            if(top <= (size/2)){
                ContainerShrink();
                resizeCount++;
            }
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

        A = B; // reset array pointer
    }

    void ContainerGrow()
    {
        int newSize = size * 1.75;    // double size of original
        int *B = new int[newSize]; // allocate new memory

        for (int i = 0; i < size; i++)
        { // copy values to new array
            B[i] = A[i];
        }

        delete[] A; // delete old array

        size = newSize; // save new size

        A = B; // reset array pointer

    }

    void ContainerShrink()
    {
         int newSize = size -0.5;    // double size of original
        int *B = new int[newSize]; // allocate new memory

        for (int i = 0; i < size; i++)
        { // copy values to new array
            B[i] = A[i];
        }

        delete[] A; // delete old array

        size = newSize; // save new size

        A = B; // reset array pointer
    }

    void CheckResize(ArrayStack stack)
    {
    }
};

// MAIN DRIVER
// Simple Array Based Stack Usage:
int main()
{
    int x = 0;
    ifstream infile;
    ArrayStack stack;

    infile.open("nums.dat");

    while (!infile.eof())
    {
        infile >> x;

        // if(x % 2 == 0) {
        //  //if(!stack.Push(x)){
        //      if(){
        //        cout<<"Push failed"<< endl;
        //      }
        //      else if(stack.Full()){

        // }
        // else if(x % 2 == 1){
        //     stack.Pop();
        // }
        // else{
        //     cout << "Else statement = " << x << endl;
        // }

        if (x % 2 == 0)
        {

            if(stack.Full()){
                stack.ContainerGrow();
                stack.Push(x);
                break;
            }

            if (!stack.Push(x))
            {
                cout << "Push failed" << endl;
            }
        }
        else if (x % 2 == 1)
            {
                stack.Pop();
            }
        else
            {
                cout << "Else statement = " << x << endl;
            }

            //   for(int i=0;i<20;i++){
            //     r = rand() % 100;
            //     r = i+1;
            //     if(!stack.Push(r)){
            //       cout<<"Push failed"<<endl;
            //     }
            //   }

            //   for(int i=0;i<7;i++){
            //     stack.Pop();
            //   }

            //   stack.Print();
        }
        cout << "Printing Stack" << endl;
        stack.Print();
    }