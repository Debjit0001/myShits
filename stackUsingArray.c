#include<stdio.h>
#define MAX_SIZE 10

void push(int stack[], int *top_idx, int item) //using pointers because we need to update the value of top in main function also(call by reference)
{ 
    // handling stack overflow
    if ((*top_idx) >= MAX_SIZE) {
        printf("\nStack is already full. \n");
        return;
    }

    stack[(*top_idx)++] = item;
}

int pop(int stack[], int *top_idx) //using pointers because we need to update the value of top in main function also(call by reference)
{
    // handling stack underflow
    if ((*top_idx) <= 0) {
        printf("\nStack is empty.");
        return -1; // -1 symbolizes unsuccessful operation
    }

    return stack[--(*top_idx)];
}

int peek(int stack[], int top) { return stack[--top]; }

void display(int stack[], int top) {
    printf("\nStack: \n");

    // printing the stack vertically from the top
    for (int i = --top; i >= 0 ; i--) {
        printf("%d \n", stack[i]);
    }
}

int main() 
{
    int stack[MAX_SIZE], top=0, choice, flag=1;

    while(flag) {
        printf("\nMain menu: \n");
        printf("\t1-> push  \n\t2-> pop  \n\t3-> peek  \n\t4-> display  \n\t5-> exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            int item;
            printf("\nEnter item to push: ");
            scanf("%d", &item);
            push(stack, &top, item);
            break;

        case 2: 
            int popped_item = pop(stack, &top);
            printf("\npopped item: %d \n", popped_item);
            break;

        case 3: 
            printf("\nItem at the top: %d \n", peek(stack, top));
            break;

        case 4:
            display(stack, top);
            break;
        
        case 5:
            flag = 0;
            break;
        
        default:
            printf("\nInvalid choice!");
            break;
        }
    }

    return 0;
}
