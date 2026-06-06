#include "monty.h"

global_t var = {NULL, NULL, NULL, 0};

/**
 * main - entry point for the Monty bytecode interpreter
 * @argc: argument count
 * @argv: array of argument strings
 * Return: 0 on success, exit codes on failure
 */
int main(int argc, char *argv[])
{
stack_t *stack = NULL;
size_t len = 0;
ssize_t read_line;
unsigned int line_num = 0;
char *opcode;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
var.file = fopen(argv[1], "r");
if (!var.file)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
while ((read_line = getline(&var.buffer, &len, var.file)) != -1)
{
line_num++;
opcode = strtok(var.buffer, " \t\n\r");
if (!opcode || opcode[0] == '#')
continue;
var.arg = strtok(NULL, " \t\n\r");

if (strcmp(opcode, "push") == 0)
f_push(&stack, line_num);
else if (strcmp(opcode, "pall") == 0)
f_pall(&stack, line_num);
else if (strcmp(opcode, "pint") == 0)
f_pint(&stack, line_num);
else if (strcmp(opcode, "pop") == 0)
f_pop(&stack, line_num);
else if (strcmp(opcode, "swap") == 0)
f_swap(&stack, line_num);
else if (strcmp(opcode, "add") == 0)
f_add(&stack, line_num);
else if (strcmp(opcode, "sub") == 0)
f_sub(&stack, line_num);
else if (strcmp(opcode, "nop") == 0)
f_nop(&stack, line_num);
else if (strcmp(opcode, "div") == 0)
f_div(&stack, line_num);
else if (strcmp(opcode, "mul") == 0)
f_mul(&stack, line_num);
else if (strcmp(opcode, "mod") == 0)
f_mod(&stack, line_num);
else if (strcmp(opcode, "pchar") == 0)
f_pchar(&stack, line_num);
else if (strcmp(opcode, "pstr") == 0)
f_pstr(&stack, line_num);
else if (strcmp(opcode, "rotl") == 0)
f_rotl(&stack, line_num);
else if (strcmp(opcode, "rotr") == 0)
f_rotr(&stack, line_num);
else if (strcmp(opcode, "stack") == 0)
f_stack(&stack, line_num);
else if (strcmp(opcode, "queue") == 0)
f_queue(&stack, line_num);
else
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_num, opcode);
clean_exit(&stack, EXIT_FAILURE);
}
}
free_stack(stack);
free(var.buffer);
fclose(var.file);
return (0);
}
