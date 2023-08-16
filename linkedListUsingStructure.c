#include<stdio.h>
#include<stdlib.h>

typedef struct listNode {
    int value;
    struct listNode* next;
} node;

// Define struct LinkedList before typedefs
struct linkedList;

typedef void (*insertAtFunc)(struct linkedList*, int, int);
typedef void (*insertFirstFunc)(struct linkedList*, int);
typedef void (*insertLastFunc)(struct linkedList*, int);

typedef struct linkedList {
    int size;
    node *head, *tail;
    insertAtFunc insertAt;
    insertFirstFunc insertFirst;
    insertLastFunc insertLast;
} LinkedList;

void insertFirst(LinkedList* list, int value) {
    node* newNode = malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else 
    {
        newNode -> next = list -> head;
        list -> head = newNode;
    }

    ++list->size;
}

void insertLast(LinkedList* list, int value) {
    node* newNode = malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;

    if (list->tail == NULL) {
        list->tail = newNode;
        list -> head = list -> tail;
    } else 
    {
        list -> tail -> next = newNode;
        list -> tail = newNode;
    }
    ++list->size;
}

void insertAt(LinkedList* list, int value, int index) {
    if(index < 0 || index > list->size)
        return;

    if(index == 0) {
        insertFirst(list, value);
        return;
    }

    if(index == list->size) {
        insertLast(list, value);
        return;
    }

    int currIdx = 1;
    node* currNode = list -> head;

    while(currIdx++ < index) 
        currNode = currNode -> next;
    
    node* newNode = malloc(sizeof(node));
    newNode->value = value;
    newNode->next = currNode -> next;
    currNode -> next = newNode;
}

// Printing the linked list
void printList(struct linkedList *list) {
    node *currNode = list -> head;

    printf("Linked list: \n");
    while(currNode != NULL) {
        printf("%d ", currNode -> value);
        currNode = currNode -> next;
    }
}

// Initializing the linked list
void initList(LinkedList *list) {
    list -> size = 0;
    list->head = NULL;
    list->insertAt = insertAt;
    list->insertFirst = insertFirst;
    list->insertLast = insertLast;
}

int main(int argc, char const *argv[])
{
    LinkedList list;
    initList(&list);

    list.insertFirst(&list, 10);
    list.insertLast(&list, 20);
    list.insertLast(&list, 30);
    list.insertLast(&list, 40);
    list.insertAt(&list, 15, 2);

    printList(&list);
    
    return 0;
}
