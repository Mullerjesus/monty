#include "monty.h"

/**
* print_stack - prints the stack
* @stk_head: stack head
* @counter: not used
* Return: no return
*/
void print_stack(stack_t **stk_head, unsigned int counter)
{
stack_t *current_node;
(void)counter;

current_node = *stk_head;
if (current_node == NULL)
return;
while (current_node)
{
printf("%d\n", current_node->n);
current_node = current_node->next;
}
}
