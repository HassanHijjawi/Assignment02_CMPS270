/*
    int size ()

    Requires: Nothing
    Effects: Returns the number of elements in the stack.

    Testing Strategy: 1) Stack has no elements.
                      2) Stack has odd number of elements.
                      3) Stack has even number of elements.

    *****************************************************************  

    bool isEmpty()
    Requires: Nothing
    Effects: Returns true is the stack has 0 elements, false otherwise.

    Testing Strategy: 1) Empty stack.
                      2) Stack contains n elements.

    ********************************************************************************   
    void push (const T &item)
    Requires: Nothing.
    Effects:  Saves a pointer to the passed value in the stack following the last-in first-out rule.

    Testing Strategy:  1) Passing NULL.
                       2) Executing the function an even number of times.
                       3) Executing the function an odd number of times.

    ********************************************************************************

    T & top ()
    Requires: Nothing.
    Effects: Returns the value of the last added element in the stack.
             If the stack was empty, it throws an error.

    Testing Strategy: 1) Stack is initially empty.
                      2) Stack contains an even number of elements.
                      3) Stack contains an odd number of elements.
                      4) Execute the function two or more consecutive runs.

    ********************************************************************************
    void pop()

    Requires: Nothing.
    Effects: Deletes the last added element to the stack only if it wasn't empty.

    Testing Strategy: 1) Perform when stack is empty
                      2) Perform when stack is not empty
                      3) Keep on performing on a non-empty stack till it becomes empty.

    ********************************************************************************* 

    friend Stack<S> operator+ (Stack <S> & A, Stack <S> & B);

    Requires: Nothing
    Effects:  Returns a stack containing the elements of A and B.
              The rule of adding is that if we insert 1 and then 2 to A and 3 then 4 to B, then the result in C will be 1 2 3 4.

    Testing Strategy: 1) Passing two null stacks
                      2) Passing one null stack and the other non-null 
                      3) Passing stacks of odd sizes
                      4) Passing stacks of even sizes
                      5) Passing stacks of different sizes 
                      6) Passing stacks of equal sizes
                      7) Passing similar stacks (equal elements and order of insertions)        
             


                         
*/

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack
{
    private:
       std:: vector <T> Elements;
    public:

        template <typename S>
        friend Stack<S> operator+ (Stack <S> & A, Stack <S> & B);

        Stack() {}

        int size ()
        {
            return Elements.size();
        }

        bool isEmpty()
        {
            if(Elements.size() == 0)
                return true;
            return false;
        }

        void push (const T &item)
        {
            Elements.push_back(item);
        }
        
        T & top ()
        {
            if(isEmpty())
            {
                 throw std::invalid_argument("The stack is empty");
            }
            T  & copy = Elements.at(Elements.size()-1);
            return copy;
        }

        void pop()
        {
            if(!isEmpty())
                Elements.pop_back();
        }
      
};

template <typename S>
Stack<S> operator+ (Stack <S> & A, Stack <S> & B)
{
    Stack <S> holdContents;
    Stack <S> C;
    while(!A.isEmpty())
    {
        holdContents.push(A.top());
        A.pop();
    }
    while(!holdContents.isEmpty())
    {
        C.push(holdContents.top());
        A.push(holdContents.top());
        holdContents.pop();
    }
    
    while(!B.isEmpty())
    {
        holdContents.push(B.top());
        B.pop();
    }
    while(!holdContents.isEmpty())
    {
        C.push(holdContents.top());
        B.push(holdContents.top());
        holdContents.pop();
    }

    return C;
}

int main()
{
    // Stack<int> myStack ;
    // int i = 5;
    // int x = 6;
    // int j = 7;
    // myStack.push(i);
    // cout<< "The last inserted element is: " << myStack.top() << endl;
    // myStack.push(x);
    // cout<< "The last inserted element is: " << myStack.top() << endl;
    // myStack.push(j);
    // cout<< "The last inserted element is: " << myStack.top() << endl;

    // cout << "The number of elements in the stack is: " << myStack.size() << endl;

    // myStack.pop();
    // cout << "After removing the last element, the last element is now: " << myStack.top() << endl;
    
    // cout << "The number of elements in the stack is: " << myStack.size() << endl;

    Stack <int> A ;
    A.push(1);
    A.push(2);

    Stack <int> B;
    B.push(3);
    B.push(5);

    Stack <int> C = A + B;
    cout <<"The last inserted element in C: " << C.top() << endl;
    cout << "The number of elements in C: " << C.size() <<endl;   

    cout << "The number of elements in A: " << A.size() <<endl;
    cout << "The number of elements in B: " << B.size();
    


    

}