#include "monty.h"

void f_push(stack_t **stack, unsigned int line_number)
{
stack_t *new_node;
int val, idx = 0;

if (!var.arg)
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
clean_exit(stack, EXIT_FAILURE);
}
if (var.arg[0] == '-')
idx++;
for (; var.arg[idx]; idx++)
{
if (!isdigit(var.arg[idx]))
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
clean_exit(stack, EXIT_FAILURE);
}
}
val = atoi(var.arg);
new_node = malloc(sizeof(stack_t));
if (!new_node)
{
fprintf(stderr, "Error: malloc failed\n");
clean_exit(stack, EXIT_FAILURE);
}
new_node->n = val;
new_node->prev = NULL;
new_node->next = *stack;
if (*stack)
(*stack)->prev = new_node;
*stack = new_node;
}

void f_pall(stack_t **stack, unsigned int line_number)
{
stack_t *runner = *stack;
(void)line_number;

while (runner)
{
printf("%d\n", runner->n);
runner = runner->next;
}
}

void f_pint(stack_t **stack, unsigned int line_number)
{
if (!stack || !*stack)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
clean_exit(stack, EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}

void f_pop(stack_t **stack, unsigned int line_number)
{
stack_t *temp;

if (!stack || !*stack)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
clean_exit(stack, EXIT_FAILURE);
}
temp = *stack;
*stack = temp->next;
if (*stack)
(*stack)->prev = NULL;
free(temp);
}
