#include<iostream>
#include <cassert>
using namespace std;

// using a template so that the stack can hold any type of data
template <typename T>
class Node {
    public:
        T val;
        Node* prev;

        Node(T val) {
            this -> val = val;
            this -> prev = NULL;
        }

        Node() {}
};

template <typename T>
class Stack {
    private:
        int size;
        Node<T>* top;

    public:
        Stack() {
            size = 0;
            top = NULL;
        }

        void push(T val) {
            if(!this->isEmpty()) {
                // the stack already has a top and so we have to create a new node and set that to top.
                Node<T>* newNode = new Node<T> (val);
                newNode->prev=top;
                top = newNode;
            } else {
                // create a node and set it as the top of stack.
                Node<T>* newNode = new Node<T> (val);
                top = newNode;
            }
            ++size;
        }

        T pop() {
            assert (!isEmpty()); // if this is false then the execution of the program will stop

            Node<T>* temp = top;
            T val = temp->val;
            top = top->prev;
            --size;
            delete temp;

            return val;
        }

        T peek() {
            assert (!isEmpty());
            return top->val;
        }

        int getSize() { return size; }
        bool isEmpty() { return top==nullptr; }

        void clear() {
            while (!isEmpty()) 
                pop();
        }

        ~Stack() {
            clear();
        }
};

int main()
{
    Stack<int> myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);

    myStack.pop();

    int top = myStack.peek();
    cout << "Top element: " << top <<endl;

    cout << "Size of stack: " << myStack.getSize() << endl;

    return 0;
}
