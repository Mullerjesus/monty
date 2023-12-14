#include "monty.h"

/**
* f_div - divides the top two elements of the stack.
* @head: stack head
* @counter: line_number
* Return: no return
*/
void f_div(stack_t **head, unsigned int counter)
{
stack_t *current = *head;

/* Check if there are at least two elements on the stack */
if (!current || !current->next)
{
fprintf(stderr, "L%d: can't div, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}

/* Check if the divisor (top element) is zero */
if (current->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}

/* Calculate the result of the division */
int result = current->next->n / current->n;

/* Update the second element with the result */
current->next->n = result;

/* Remove the first element from the stack */
*head = current->next;

/* Free the memory of the removed element */
free(current);
}
