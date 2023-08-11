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
        bool empty;
        Node* top;

    public:
        Stack() {
            size = 0;
            empty = true;
            top = NULL;
        }

        void push(int val) {
            if(!this->empty) {
                // the stack already has a top and so we have to create a new node and set that to top.
                Node* newNode = new Node(val);
                newNode->prev=top;
                top = newNode;
            } else {
                // create a node and set it as the top of stack.
                Node *newNode = new Node (val);
                top = newNode;
                this -> empty = false;
            }
            ++size;
        }

        int pop() {
            assert (!isEmpty()); // if this is false then the execution of the program will stop

            Node* temp = top;
            top = top->prev;
            delete temp;
            --size;
        }

        int peek() {
            assert (!isEmpty());
            return top->val;
        }

        int getSize() { return size; }
        bool isEmpty() { return empty; }

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
