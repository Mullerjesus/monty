#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

typedef struct
{
int items[STACK_SIZE];
int top;
} Stack;

void push(Stack *stack, int value)
{
if (stack->top < STACK_SIZE - 1)
{
stack->top++;
stack->items[stack->top] = value;
}
else
{
printf("Error: Stack overflow\n");
exit(EXIT_FAILURE);
}
}

int pop(Stack *stack)
{
if (stack->top >= 0)
{
int value = stack->items[stack->top];
stack->top--;
return value;
}
else
{
printf("Error: can't pop an empty stack\n");
exit(EXIT_FAILURE);
}
}

int main(void)
{
Stack stack;
stack.top = -1;

push(&stack, 1);
push(&stack, 2);
push(&stack, 3);

printf("Before popping: %d\n", pop(&stack));
printf("After popping: %d\n", pop(&stack));

return (0);
}
