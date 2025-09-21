#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define MAX_SIZE 100

typedef struct
{
    char arr[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack *s)
{
    s->top = -1;
}

int isFull(Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, char x)
{
    if(isFull(s)) {
        printf("Stack overflow!");
    }
    else {
        s->top++;
        s->arr[s->top] = x;
    }
}

int pop(Stack *s)
{
    char x;
    if(isEmpty(s)) {
        printf("Stack underflow!");
        return -1;
    }
    else {
        x = s->arr[s->top];
        s->top--;
        return x;
    }
}

int peek(Stack *s)
{
    if(isEmpty(s)) {
        printf("Stack underflow!");
        return -1;
    }
    else {
        return s->arr[s->top];
    }
}

int length(Stack *s)
{
    return s->top == -1 ? 0 : s->top;
}

#endif // STACK_H_INCLUDED
