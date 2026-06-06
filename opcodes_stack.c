#include "monty.h"

/**
 * f_push - pushes an element to the stack or queue based on mode
 * @stack: double pointer to the stack head
 * @line_number: current bytecode file line number
 */
void f_push(stack_t **stack, unsigned int line_number)
{
stack_t *new_node, *tail;
int val, idx = 0;

if (!var.arg)
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
clean_exit(stack, EXIT_FAILURE);
}
if (var.arg[0] == '-')
idx++;
if (!var.arg[idx])
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
clean_exit(stack, EXIT_FAILURE);
}
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
if (var.data_mode == 0 || !*stack)
{
new_node->prev = NULL;
new_node->next = *stack;
if (*stack)
(*stack)->prev = new_node;
*stack = new_node;
}
else
{
tail = *stack;
while (tail->next)
tail = tail->next;
tail->next = new_node;
new_node->prev = tail;
new_node->next = NULL;
}
}

/**
 * f_pall - prints all values on the stack, starting from the top
 * @stack: double pointer to the stack head
 * @line_number: unused line number parameter
 */
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

/**
 * f_pint - prints the value at the top of the stack
 * @stack: double pointer to the stack head
 * @line_number: current bytecode file line number
 */
void f_pint(stack_t **stack, unsigned int line_number)
{
if (!stack || !*stack)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
clean_exit(stack, EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}

/**
 * f_pop - removes the top element of the stack
 * @stack: double pointer to the stack head
 * @line_number: current bytecode file line number
 */
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
