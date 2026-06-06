#include "monty.h"

void free_stack(stack_t *head)
{
stack_t *temp;

while (head)
{
temp = head->next;
free(head);
head = temp;
}
}

void clean_exit(stack_t **stack, int status)
{
if (stack && *stack)
free_stack(*stack);
if (var.buffer)
free(var.buffer);
if (var.file)
fclose(var.file);
exit(status);
}
