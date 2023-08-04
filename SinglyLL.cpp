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
        LinkedList() {}

        Node* head = NULL;
        Node* tail = NULL;

        void addFirst(int val) {
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

        void deleteFirst() {
            if(this->empty == false) {
                Node *tempHead = head;
                head = head ->nextNode;
                delete tempHead;
            }
        }

        void addLast(int val) {
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

        void deleteLast() {
            
        }

        void insertAtIndex(int idx, int val) {
            if (idx > size || idx < 0) {
            throw std::invalid_argument( "received invalid index" );
            }

            if(idx == 0) {
                this->addFirst(val);
                return;
            }

            if(idx == size) {
                this->addLast(val);
                return;
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
            cout << endl;
        }

        bool isEmpty() { return empty; }
        int getSize() { return size; }

        ~LinkedList() {
            Node* currNode = head;
            while(currNode != NULL) {
                Node* nextNode = currNode->nextNode;
                delete currNode;
                currNode = nextNode;
            }
        }
};

int main()
{
    LinkedList list;

    list.addLast(10);

    list.addLast(5);
    list.addLast(6);
    list.addLast(7);
    list.printList();

    list.insertAtIndex(3, 12);
    list.printList();

    list.deleteFirst();
    list.printList();

    return 0;
}
