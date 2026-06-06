#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>

typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct global_s
{
FILE *file;
char *arg;
char *buffer;
} global_t;

extern global_t var;

void free_stack(stack_t *head);
void clean_exit(stack_t **stack, int status);

void f_push(stack_t **stack, unsigned int line_number);
void f_pall(stack_t **stack, unsigned int line_number);
void f_pint(stack_t **stack, unsigned int line_number);
void f_pop(stack_t **stack, unsigned int line_number);
void f_swap(stack_t **stack, unsigned int line_number);
void f_add(stack_t **stack, unsigned int line_number);
void f_sub(stack_t **stack, unsigned int line_number);
void f_nop(stack_t **stack, unsigned int line_number);
void f_div(stack_t **stack, unsigned int line_number);
void f_mul(stack_t **stack, unsigned int line_number);
void f_mod(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
