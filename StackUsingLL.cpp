#include<iostream>
#include <cassert>
using namespace std;

class Node {
    public:
        int val;
        Node* prev;

        Node(int val) {
            this -> val = val;
            this -> prev = NULL;
        }

        Node() {}
};

class Stack : private Node {
    private:
        int size;
        Node* top;

    public:
        Stack() {
            size = 0;
            top = NULL;
        }

        void push(int val) {
            if(!this->isEmpty()) {
                // the stack already has a top and so we have to create a new node and set that to top.
                Node* newNode = new Node(val);
                newNode->prev=top;
                top = newNode;
            } else {
                // create a node and set it as the top of stack.
                Node *newNode = new Node (val);
                top = newNode;
            }
            ++size;
        }

        int pop() {
            assert (!isEmpty()); // if this is false then the execution of the program will stop

            Node* temp = top;
            int val = temp->val;
            top = top->prev;
            --size;
            delete temp;

            return val;
        }

        int peek() {
            assert (!isEmpty());
            return top->val;
        }

        int getSize() { return size; }
        bool isEmpty() { return top==nullptr; }

        ~Stack() {
            while (!isEmpty()) 
                pop();
        }
};

int main()
{
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    stack.pop();

    int top = stack.peek();
    cout << "Top element: " << top <<endl;

    cout << "Size of stack: " << stack.getSize() << endl;

    return 0;
}
