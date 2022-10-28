#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class Stack
{
    private:
       std:: vector <T> Elements;
    public:
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

int main()
{
    Stack<int> myStack ;
    int i = 5;
    int x = 6;
    int j = 7;
    myStack.push(i);
    cout<< "The last inserted element is: " << myStack.top() << endl;
    myStack.push(x);
    cout<< "The last inserted element is: " << myStack.top() << endl;
    myStack.push(j);
    cout<< "The last inserted element is: " << myStack.top() << endl;

    cout << "The number of elements in the stack is: " << myStack.size() << endl;

    myStack.pop();
    cout << "After removing the last element, the last element is now: " << myStack.top() << endl;
    
    cout << "The number of elements in the stack is: " << myStack.size() << endl;

    


    

}