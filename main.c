#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next; // pointer to the next element in linked list
};

int main()
{

    struct node *head, *tail;
    head = NULL, tail = NULL; // because currently the linked list is empty
    int size = 0;

    // insertion at the tail/end:
    int flag = 1; // C te 1=true ar 0=false
    while(flag)
    {
        // first e input ta nebo:
        int val;
        printf("Enter a value to insert: ");
        scanf("%d", &val);

        /* allocating memory for new node */
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        /* assign data and next pointer of the new node*/
        newNode->value = val;
        newNode->next = NULL;

        if (head == NULL)
        {   /* update pointer variables */
            head = newNode;
            tail = head;
        }
        else {
            /* update pointer variables */
            tail->next = newNode;
            tail = tail->next;
        }
        ++size;

        //sesh e dekhbo user aro insert korte chaiche ki na
        printf("do you want to keep inserting?\n");
        scanf("%d", &flag);
    }

    // printing the linked list:
    printf("Linked List:\n");
    struct node *tempNode = (struct node *)malloc(sizeof(struct node));
    tempNode = head;           // assigning a temporary node to traverse through the entire list
    while ((tempNode != NULL)) // traversing till end of the list
    { 
        printf("%d ", tempNode->value);
        tempNode = tempNode->next;
    }

    return 0;
}
