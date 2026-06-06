#include "monty.h"

void f_swap(stack_t **stack, unsigned int line_number)
{
int temp_val;

if (!stack || !*stack || !(*stack)->next)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
clean_exit(stack, EXIT_FAILURE);
}
temp_val = (*stack)->n;
(*stack)->n = (*stack)->next->n;
(*stack)->next->n = temp_val;
}

void f_add(stack_t **stack, unsigned int line_number)
{
if (!stack || !*stack || !(*stack)->next)
{
fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
clean_exit(stack, EXIT_FAILURE);
}
(*stack)->next->n += (*stack)->n;
f_pop(stack, line_number);
}

void f_sub(stack_t **stack, unsigned int line_number)
{
if (!stack || !*stack || !(*stack)->next)
{
fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
clean_exit(stack, EXIT_FAILURE);
}
(*stack)->next->n -= (*stack)->n;
f_pop(stack, line_number);
}

void f_nop(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
}

void f_div(stack_t **stack, unsigned int line_number)
{
if (!stack || !*stack || !(*stack)->next)
{
fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
clean_exit(stack, EXIT_FAILURE);
}
if ((*stack)->n == 0)
{
fprintf(stderr, "L%u: division by zero\n", line_number);
clean_exit(stack, EXIT_FAILURE);
}
(*stack)->next->n /= (*stack)->n;
f_pop(stack, line_number);
}

void f_mul(stack_t **stack, unsigned int line_number)
{
if (!stack || !*stack || !(*stack)->next)
{
fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
clean_exit(stack, EXIT_FAILURE);
}
(*stack)->next->n *= (*stack)->n;
f_pop(stack, line_number);
}

void f_mod(stack_t **stack, unsigned int line_number)
{
if (!stack || !*stack || !(*stack)->next)
{
fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
clean_exit(stack, EXIT_FAILURE);
}
if ((*stack)->n == 0)
{
fprintf(stderr, "L%u: division by zero\n", line_number);
clean_exit(stack, EXIT_FAILURE);
}
(*stack)->next->n %= (*stack)->n;
f_pop(stack, line_number);
}
