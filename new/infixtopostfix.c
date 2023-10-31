#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
};

int isEmpty(struct stack *sp)
{
    if (sp->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct stack *sp)
{
    if (sp->top == sp->size - 1)
        return 1;
    else
        return 0;
}

void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

void pop(struct stack *ptr)
{
    if (isEmpty(ptr))
        printf("Stack Underflow! Cannot pop from the stack\n");
    else
    {
      int val = ptr->arr[ptr->top];
      ptr->top--;
      return val;
    }
}

int precedence(char ch){

    if(ch == '^')
        return 4;
    else if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2; 
    else
        return 0;
}

int isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/'||ch == '^') 
        return 1;
    else
        return 0;
}







int main()
{
    char * infix = "x-y/z-k*d";
    printf("postfix is %s", infixToPostfix(infix));
    return 0;
}