#include <stdio.h>
#define MAXSIZE 10   // Maxsize of stack

int stack[MAXSIZE];  // Stack with array
int top;    //Top of the Stack

void init_stack () { 
    top = -1;
}

int push(int val) {
    if (top >= MAXSIZE-1) {
        printf("\n   <Stack Overflow>\n");
        return -1;
    }
    stack[++top] = val;
    printf("[%d PUSH!] \n",val);
    return val;
}

int pop(void) {
    if (top < 0) {
        printf("\n   <Stack Underflow>\n");
        return -1;
    }
    return stack[top--];
}


void print_stack() {
    int i;
    printf ("\n Stack From Top-----> To Bottom\n");
    for (i = top; i>=0; i--)
        printf ("%-6d", stack[i]);
}

int main(void)
{
    int i;
    init_stack();
    
    printf ("\nPush 5, 4, 7, 8, 2, 1\n");
    push(5);
    push(4);
    push(7);
    push(8);
    push(2);
    push(1);
    print_stack();
    
    printf("\nPop\n");
    i = pop();
    print_stack();
    printf("\n  popped value is %d\n", i);
    
    printf("\nPush 3, 2, 5, 7, 2\n");
    push(3);
    push(2);
    push(5);
    push(7);
    push(2);
    print_stack();
    
    printf("\nNow Stack is full, push 3");
    push(3);
    print_stack();
    
    printf("\nInitialize stack");
    init_stack();
    print_stack();
    
    printf("\nNow Stack is empty, pop");
    i = pop();
    print_stack();
    printf("\n  popped value is %d\n", i);

    return 0;
}