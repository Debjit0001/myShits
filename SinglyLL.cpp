#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node *nextNode;

    Node() {}

    Node(int val) {
        this->val = val;
        this->nextNode = NULL;
    }
};

class LinkedList : public Node {
    private:
        int size = 0;
        bool empty = true;

    public: 
        LinkedList() {
            // do nothing here.
        }

        Node* head = NULL;
        Node* tail = NULL;
        void insertAtTail(int val) {
            if (empty == false){
                tail -> nextNode = new Node(val);
                tail = tail -> nextNode;
                size++;
            }
            else {
                head = new Node(val);
                tail = head;
                empty = false;
                size++;
            }
        }

        void insertAtHead(int val) {
            if(empty == false) {
                Node* tempNode = new Node(val);
                tempNode -> nextNode = head;
                head = tempNode;
                size++;
            }
            else {
                head = new Node(val),
                tail=head;
                empty =false;
                size++;
            }
        }

        void printList() {
            if(empty == true) {
                cout << "List is empty" << endl;
            }
            else {
                Node* tempNode = head;
                while(tempNode != NULL) {
                    cout << tempNode->val << " ";
                    tempNode = tempNode->nextNode;
                }
            }
        }

        void insertAtIndex(int idx, int val) {
            if (idx > size || idx < 1) {
            throw std::invalid_argument( "received invalid index" );
            }

            int currIdx = 0;
            Node* currNode = head;

            while(currIdx <= idx) {
                if(currIdx == idx-1) {
                    Node* tempNode = new Node(val);
                    tempNode -> nextNode = currNode->nextNode;
                    currNode->nextNode = tempNode;
                    size++;
                }

                currNode = currNode -> nextNode;
                currIdx++;
            }
        }

        bool isEmpty() { return empty; }
        int getSize() { return size; }
};

int main()
{
    LinkedList list;

    list.insertAtTail(10);
    list.printList();

    list.insertAtTail(5);
    list.insertAtTail(6);
    list.insertAtTail(7);
    list.printList();

    list.insertAtIndex(2, 12);
    list.printList();

    return 0;
}
