#include "monty.h"

/**
* f_pstr - Prints the string starting top of the stack, followed by a new line.
* @head: Stack head
* @counter: Line number
* Return: No return
*/
void f_pstr(stack_t **head, unsigned int counter)
{
stack_t *current = *head;
(void)counter;

while (current && current->n > 0 && current->n <= 127)
{
printf("%c", current->n);
current = current->next;
}

printf("\n");
}
