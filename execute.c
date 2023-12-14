#include "monty.h"

/* ... (other function prototypes) ... */

/**
* execute_opcode - executes a specific opcode
* @opcode: the opcode to execute
* @stack: head linked list - stack
* @counter: line_counter
* @file: pointer to monty file
* Return: no return
*/
static void execute_opcode(const char *opcode, stack_t **stack,
		unsigned int counter, FILE *file)
{
unsigned int i = 0;

/* Iterate through the list of opcodes to find a match */
while (opst[i].opcode && opcode)
{
if (strcmp(opcode, opst[i].opcode) == 0)
{
opst[i].f(stack, counter);
return;
}
i++;
}

/* Handle the case when the opcode is not recognized */
if (opcode && opst[i].opcode == NULL)
{
fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
fclose(file);
free(content);
free_stack(*stack);
exit(EXIT_FAILURE);
}
}

/**
* execute - executes the opcode
* @content: line content
* @stack: head linked list - stack
* @counter: line_counter
* @file: pointer to monty file
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
char *opcode;

/* Tokenize the content to extract the opcode */
opcode = strtok(content, " \n\t");

/* Ignore comments and empty lines */
if (opcode && opcode[0] == '#')
return (0);

/* Extract the argument for opcodes that require one */
bus.arg = strtok(NULL, " \n\t");

/* Execute the opcode */
execute_opcode(opcode, stack, counter, file);

return (1);
}
