//Stack Program Using Array
#include<stdio.h>
#include<stdlib.h>

void push(int *s,int* top, int element);
int pop(int *s,int *top);
int full(int *top,const int size);
int empty(int *top);
void init(int *top);
void display(int *s,int *top);

int main()
{
    const int SIZE = 10; /* stack size */

    int top, elem;
    int stack[SIZE];

    init(&top);
    printf("--Push elements into stack --\n");
    /* push elements into stack */
    while(!full(&top,SIZE))
    {
        printf("Enter a number to push into the stack:");
        scanf("%d",&elem);
        push(stack,&top,elem);
        display(stack,&top);
    }
    printf("Stack is full\n\n");

    printf("--Pop elements into stack --\n");
    while(!empty(&top))
    {
        elem = pop(stack,&top);
        printf("pop %d from the stack\n",elem);

        display(stack,&top);
    }
    printf("Stack is empty\n");
    return 0;
}
/*
initialize stack pointer
*/
void init(int *top)
{
    *top = 0;
}
/*
push an element into stack
precondition: the stack is not full
*/
void push(int *s,int* top, int element)
{
    s[(*top)++] = element;
}
/*
remove an element from stack
precondition: stack is not empty
*/
int pop(int *s,int *top)
{
    return s[--(*top)];
}
/*
return 1 if stack is full, otherwise return 0
*/
int full(int *top,const int size)
{
    if(*top == size){
        return 1;
    }
    else{
        return 0;
    }
}
/*
return 1 if the stack is empty, otherwise return 0
*/
int empty(int *top)
{
    if(*top == 0){
        return 1;
    }else{
        return 0;
    }
}
/*
    display stack content
*/
void display(int *s,int *top)
{
    printf("Stack: ");
    int i;
    for(i = 0; i < *top; i++)
    {
        printf("%d ",s[i]);
    }
    printf("\n");
}