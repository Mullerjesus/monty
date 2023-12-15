#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    char *content = NULL;
    FILE *file;
    size_t size = 0;
    ssize_t read_line = 1;
    unsigned int counter = 0;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (read_line >= 0)
    {
        read_line(&content, &size, file);
        if (read_line == -1)
            break;

        counter++;
        /* Rest of the code */
    }

    free(content);
    fclose(file);
    /* Rest of the code */

    return 0;
}
