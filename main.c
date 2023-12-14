#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "monty.h"

/**
* main - Entry point for Monty bytecode interpreter
* @argc: Number of arguments
* @argv: Array of arguments
*
* Return: 0 on success, 1 on failure
*/
int main(int argc, char *argv[])
{
FILE *bytecode_file;
char *line = NULL;
size_t len = 0;
ssize_t read;
int line_number = 0;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

bytecode_file = fopen(argv[1], "r");
if (bytecode_file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}

while ((read = getline(&line, &len, bytecode_file)) != -1)
{
line_number++;
if (line[0] == '\n' || line[0] == '#')
continue;
tokenize(line);
execute_opcode();
}

free_stack();
fclose(bytecode_file);
if (line)
free(line);
return (0);
}
