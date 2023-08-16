#include <stdio.h>
#include <stdlib.h>

// Linked List Node Structure
struct StackNode {
    int data;
    struct StackNode *next;
};

// Function Pointer Types
typedef void (*PushFunc)(struct Stack *, int);
typedef int (*PopFunc)(struct Stack *);

// Stack Structure
struct Stack {
    struct StackNode *top;
    PushFunc push;
    PopFunc pop;
};

// Push Function
void push(struct Stack *stack, int data) {
    struct StackNode *newNode = (struct StackNode *)malloc(sizeof(struct StackNode));
    if (newNode == NULL) {
        // Handling memory allocation error
        return;
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Pop Function
int pop(struct Stack *stack) {
    if (stack->top == NULL) {
        // Handling empty stack case
        return INT_MIN; 
    }
    int data = stack->top->data;
    struct StackNode *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Initializing the Stack
void initStack(struct Stack *stack) {
    stack->top = NULL;
    stack->push = push;
    stack->pop = pop;
}

int main() {
    struct Stack myStack;
    initStack(&myStack);

    myStack.push(&myStack, 10);
    myStack.push(&myStack, 20);

    printf("Popped: %d\n", myStack.pop(&myStack));
    printf("Popped: %d\n", myStack.pop(&myStack));

    return 0;
}
