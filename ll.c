#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node;

typedef struct linked_list {
    node* head;
    int size;
} linked_list;

node* init(int val) {
    node* newNode = (node*) malloc ( sizeof(node) );

    newNode -> val = val;
    newNode -> next = NULL;

    return newNode;
}

void insertAtHead(linked_list* list, int val) {
    node* newNode = init(val);

    if(list->head == NULL){
        list->head = newNode;
        list -> size = 1;
    }
    else {
        newNode -> next = list -> head;
        list -> head = newNode;
    }
    list->size++;
}

void insertAtTail(linked_list* list, int val) {
    node* temp = list->head;
    node* newNode = init(val);

    if(list->head == NULL) {
        list->head = newNode;
        list -> size = 1;
        return;
    }

    while(temp -> next != NULL) 
        temp = temp->next;

    temp->next = newNode;
    list->size++;
}

void insertAt(linked_list* list, int val, int index) {
    if(index < 0 || index > list->size)
        return;

    if(index == 0) {
        insertAtHead(list, val);
        return ;
    }

    if(index == list->size) {
        insertAtTail(list, val);
    }

    int counter = 0;
    node* temp = list->head;
    while(counter++ < index)
        temp = temp->next;

    node* nextNode = temp->next;
    node* newNode = init(val);

    temp->next = newNode;
    newNode->next = nextNode;
    list->size++;
}

void rev(linked_list* list) {
    if(list->head->next == NULL) {
        return;
    }
}

void display(linked_list* list) {
    node* temp = list->head;

    while(temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL \n");
}

int main(int argc, char const *argv[])
{
    linked_list list;
    insertAtTail(&list, 10);
    insertAtTail(&list, 20);
    insertAtTail(&list, 30);
    insertAtTail(&list, 40);
    insertAtHead(&list, 0);

    insertAt(&list, 25, 2);

    display(&list);
    
    return 0;
}
