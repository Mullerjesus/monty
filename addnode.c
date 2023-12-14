#include "monty.h"

/**
* addnode - add node to the head stack
* @head: head of the stack
* @n: new_value
* Return: no return
*/
void addnode(stack_t **head, int n)
{
/* Declare and allocate memory for the new node */
stack_t *new_node = malloc(sizeof(stack_t));

/* Check if memory allocation was successful */
if (new_node == NULL)
{
fprintf(stderr, "Error: Failed to allocate memory for a new node\n");
exit(EXIT_FAILURE);
}

/* Set the value of the new node */
new_node->n = n;

/* Update links to insert the new node at the head of the stack */
new_node->next = *head;
new_node->prev = NULL;

/* Update the previous pointer of the existing head, if it exists */
if (*head)
(*head)->prev = new_node;

/* Update the head to point to the new node */
*head = new_node;
}
