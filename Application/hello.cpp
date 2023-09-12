#include <iostream>
#include <cstdlib>

using namespace std;

struct node
{
    int value;
    node *next;

    // constructor
    node(int val) : value(val), next(nullptr) {}

    // Destructor to free dynamically allocated memory (if any)
    ~node()
    {
        if (next)
        {
            delete next;
        }
    }
};

struct queue
{
    node *head, *tail;

    queue() : head(nullptr), tail(nullptr) {}

    void offer(int val)
    {
        node *newNode = new node(val);

        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    int poll() {
        if (!this->head) {
            cout << "Empty queue exception!" << endl;
            return INT_MIN;
        }

        int value = tail->value;

        if (this->head != this->tail)
        {
            node *temp = this->head;
            while (temp->next != this->tail) {
                temp = temp->next;
            }
            delete this->tail;
            tail = temp;
        }
        else {
            delete this->head;
            head = nullptr;
            tail = nullptr;
        }

        return value;
    }

    void display()
    {
        node *temp = this->head;
        while (temp)
        {
            cout << temp->value << " ";
            temp = temp->next;
        } cout << endl;
    }
};

int main()
{
    queue myQueue;
    myQueue.offer(5);
    myQueue.offer(4);
    myQueue.offer(3);
    myQueue.offer(2);

    myQueue.poll();
    myQueue.display();

    return 0;
}