#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
* process_monty_file - process the Monty file
* @file_path: path to the Monty file
*/
void process_monty_file(const char *file_path)
{
FILE *file = fopen(file_path, "r");
char *content = NULL;
size_t size = 0;
ssize_t read_line = 1;
stack_t *stack = NULL;
unsigned int counter = 0;

bus.file = file;

if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", file_path);
exit(EXIT_FAILURE);
}

while (read_line > 0)
{
content = NULL;
read_line = getline(&content, &size, file);
bus.content = content;
counter++;

if (read_line > 0)
{
execute(content, &stack, counter, file);
}

free(content);
}

free_stack(stack);
fclose(file);
}

/**
* main - Monty code interpreter
* @argc: number of arguments
* @argv: Monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

process_monty_file(argv[1]);

return (0);
}
