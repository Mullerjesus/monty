#include "monty.h"

/**
* push_stack - add node to the stack
* @stack: stack head
* @line_number: line number
* Return: no return
*/
void push_stack(stack_t **stack, unsigned int line_number)
{
int value, i = 0, invalid_flag = 0;

if (global_data.argument)
{
if (global_data.argument[0] == '-')
i++;
for (; global_data.argument[i] != '\0'; i++)
{
if (global_data.argument[i] > 57 || global_data.argument[i] < 48)
invalid_flag = 1;
}
if (invalid_flag == 1)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
fclose(global_data.file);
free(global_data.content);
free_stack(*stack);
exit(EXIT_FAILURE);
}
}
else
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
fclose(global_data.file);
free(global_data.content);
free_stack(*stack);
exit(EXIT_FAILURE);
}
value = atoi(global_data.argument);
if (global_data.lifo == 0)
add_node(stack, value);
else
add_queue(stack, value);
}
