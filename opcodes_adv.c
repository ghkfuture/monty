#include "monty.h"

/**
 * f_pchar - prints the char at the top of the stack
 * @stack: double pointer to the stack head
 * @line_number: current bytecode file line number
 */
void f_pchar(stack_t **stack, unsigned int line_number)
{
if (!stack || !*stack)
{
fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
clean_exit(stack, EXIT_FAILURE);
}
if ((*stack)->n < 0 || (*stack)->n > 127)
{
fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
clean_exit(stack, EXIT_FAILURE);
}
printf("%c\n", (*stack)->n);
}

/**
 * f_pstr - prints the string starting at the top of the stack
 * @stack: double pointer to the stack head
 * @line_number: current bytecode file line number
 */
void f_pstr(stack_t **stack, unsigned int line_number)
{
stack_t *runner = *stack;
(void)line_number;

while (runner && runner->n > 0 && runner->n <= 127)
{
printf("%c", runner->n);
runner = runner->next;
}
printf("\n");
}

/**
 * f_rotl - rotates the stack to the top
 * @stack: double pointer to the stack head
 * @line_number: current bytecode file line number
 */
void f_rotl(stack_t **stack, unsigned int line_number)
{
stack_t *top, *tail;
(void)line_number;

if (!stack || !*stack || !(*stack)->next)
return;

top = *stack;
tail = *stack;
while (tail->next)
tail = tail->next;

*stack = top->next;
(*stack)->prev = NULL;
tail->next = top;
top->prev = tail;
top->next = NULL;
}

/**
 * f_rotr - rotates the stack to the bottom
 * @stack: double pointer to the stack head
 * @line_number: current bytecode file line number
 */
void f_rotr(stack_t **stack, unsigned int line_number)
{
stack_t *tail;
(void)line_number;

if (!stack || !*stack || !(*stack)->next)
return;

tail = *stack;
while (tail->next)
tail = tail->next;

tail->prev->next = NULL;
tail->next = *stack;
tail->prev = NULL;
(*stack)->prev = tail;
*stack = tail;
}

/**
 * f_stack - sets the format of the data to a stack (LIFO)
 * @stack: double pointer to the stack head
 * @line_number: current bytecode file line number
 */
void f_stack(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
var.data_mode = 0;
}

/**
 * f_queue - sets the format of the data to a queue (FIFO)
 * @stack: double pointer to the stack head
 * @line_number: current bytecode file line number
 */
void f_queue(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
var.data_mode = 1;
}
