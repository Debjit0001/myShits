#include<stdio.h>
#include<stdlib.h>

typedef struct listNode {
    int value;
    struct listNode* next;
} node;

// Defining struct struct linkedList before typedefs
struct linkedList;

typedef void (*insertAtFunc)(struct linkedList*, int, int);
typedef void (*insertFirstFunc)(struct linkedList*, int);
typedef void (*insertLastFunc)(struct linkedList*, int);
typedef void (*deleteAtFunc)(struct linkedList*, int);
typedef void (*deleteFirstFunc)(struct linkedList*);
typedef void (*deleteLastFunc)(struct linkedList*);
typedef void (*reverseFunc)(struct linkedList*);

struct linkedList {
    int size;
    node *head, *tail;
    insertAtFunc insertAt;
    insertFirstFunc insertFirst;
    insertLastFunc insertLast;
    deleteAtFunc deleteAt;
    deleteFirstFunc deleteFirst;
    deleteLastFunc deleteLast;
    reverseFunc reverse;
};

void insertFirst(struct linkedList* list, int value) {
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

void insertLast(struct linkedList* list, int value) {
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

void insertAt(struct linkedList* list, int value, int index) {
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

void deleteAt(struct linkedList* list, int index) {
    if(index < 0 || index > list->size)
        return;

    //Special case: deleting head node
    if(index == 0) {
        node* tempNode = list -> head;
        list -> head = list -> head -> next;
        free(tempNode);
        --list->size;
        return;
    }

    int currIdx = 1;
    node* currNode = list -> head;
    while(currIdx++ < index) 
        currNode = currNode -> next;

    node* delNode = currNode -> next;
    currNode -> next = delNode -> next;
    free(delNode);
    --list->size;
}

void deleteFirst(struct linkedList* list) { deleteAt(list, 0); }

void deleteLast(struct linkedList* list) { deleteAt(list, list->size); }

void reverse(struct linkedList *list) {
    if(list -> size < 2) {
        return;
    }
    list -> tail = list -> head;

    node* prev = NULL;
    node* present = list -> head;
    node* next = present -> next;

    while(present != NULL) {
        present -> next = prev;
        prev = present;
        present = next;
        if(next != NULL) 
            next = next -> next;
    }

    list -> head = prev;
}

// Printing the linked list
void printList(struct linkedList *list) {
    node *currNode = list -> head;

    printf("Linked list: \n");
    while(currNode != NULL) {
        printf("%d ", currNode -> value);
        currNode = currNode -> next;
    }
    printf("\n");
}

// Initializing the linked list
void initList(struct linkedList *list) {
    list -> size = 0;
    list -> head = NULL;
    list -> insertAt = insertAt;
    list -> insertFirst = insertFirst;
    list -> insertLast = insertLast;
    list -> deleteAt = deleteAt;
    list -> deleteFirst = deleteFirst;
    list -> deleteLast = deleteLast;
    list -> reverse = reverse;
}

int main(int argc, char const *argv[])
{
    struct linkedList list;
    initList(&list);

    list.insertFirst(&list, 10);
    list.insertLast(&list, 20);
    list.insertLast(&list, 30);
    list.insertLast(&list, 40);

    list.insertAt(&list, 15, 2);
    printList(&list);

    // list.deleteAt(&list, 2);
    // list.deleteLast(&list);
    // printList(&list);

    list.reverse(&list);
    printList(&list);
    printf("%d\n", list.tail->value);
    
    return 0;
}
