#include "monty.h"

/**
 * push - adds a new node at the beginning of a stack_t list
 *
 * @cmd: access specific data for command
 * Return: address of new node, or NULL if failed
 */

void push(cmd_t *cmd)
{
  stack_t **h = cmd->head;
  stack_t *new = NULL;

  if (h == NULL)
    {
      printf("L%d: usage: push integer\n", cmd->line_number);
      exit(EXIT_FAILURE);
    }

  new = malloc(sizeof(stack_t));
  if (new == NULL)
      exit(EXIT_FAILURE);
  
  if (*h == NULL)
    {
      new->n = cmd->arg;
      new->next = *h;
      new->prev = NULL;
      *h = new;
      return;
    }
  (*h)->prev = new;
  new->n = cmd->arg;
  new->next = *h;
  new->prev = NULL;
  *h = new;
  return;
}

/**
 * pall - prints all elements of a doubly linked list
 *
 * @cmd: data specific variables for command
 */

void pall(cmd_t *cmd)
{
  stack_t *h = *cmd->head;

  if (h == NULL)
      return;

  while (h != NULL)
    {
      printf("%d\n", h->n);
      h = h->next;
    }
}

/**
 * pint - prints the value at the top of the stack, followed by a new line
 *
 * @cmd: access to specific data from command struct
 */

void pint(cmd_t *cmd)
{
  stack_t *h = *cmd->head;

  if (h == NULL)
    {
      printf("L%d: can't pint, stack empty\n", cmd->line_number);
      exit(EXIT_FAILURE);
    }
  
  printf("%d\n", h->n);
}


/**
 * pop - remove top element of the stack
 *
 * @cmd: access to specific data from command struct
 */

void pop(cmd_t *cmd)
{
  stack_t **h = cmd->head;
  stack_t *current = NULL;

    if (*h == NULL || h == NULL)
      {
	printf("L%d: can't pop an empty stack\n", cmd->line_number);
	exit(EXIT_FAILURE);
      }

    current = *h;
    *h = (*h)->next;
    free(current);
  }

/**
 * swap - swaps the top two elements of the stack
 *
 * @cmd: access to specific data from command struct
 */

void swap(cmd_t *cmd)
{
  stack_t **h = cmd->head;
  stack_t *first = NULL;
  stack_t *second = NULL;
  stack_t *third = NULL;

  if (*h == NULL || h == NULL || (*h)->next == NULL)
    {
      printf("L%d: can't swap, stack too short\n", cmd->line_number);
      exit(EXIT_FAILURE);
    }
  first = *h;
  second = (*h)->next;
  third = second->next;

  first->next = second->next;
  second->next = first;
  third->prev = first;
  first->prev = second;
  second->prev = NULL;
  *h = second;
}

/**
 * add - adds the top two elements of the stack
 *
 * @cmd: access to specific data from command struct
 */

void add(cmd_t *cmd)
{
  stack_t **h = cmd->head;
  stack_t *node_1 = NULL;
  stack_t *node_2 = NULL;
  int sum = 0;

  if (*h == NULL || h == NULL || (*h)->next == NULL)
    {
      printf("L%d: can't add, stack too short\n", cmd->line_number);
      exit(EXIT_FAILURE);
    }
  
  node_1 = *h;
  node_2 = (*h)->next;

  sum = node_1->n + node_2->n;
  node_2->n = sum;

  pop(cmd);
}

/**
 * nop - does not do anything
 *
 * @cmd: access to useful variables from command struct
 */

void nop(cmd_t *cmd)
{
  return;
}

/**
 * sub - subtracts the top element of the stack from the second top element of the stack
 *
 * @cmd: access to useful variables from command struct
 */

void sub(cmd_t *cmd)
{
  stack_t **h = cmd->head;
  stack_t *node_1 = NULL;
  stack_t *node_2 = NULL;
  int diff = 0;

  if (h == NULL || *h == NULL || (*h)->next == NULL)
    {
      printf("L%d: can't sub, stack too short\n", cmd->line_number);
      exit(EXIT_FAILURE);
    }
  
  node_1 = *h;
  node_2 = (*h)->next;

  diff = node_2->n - node_1->n;
  node_2->n = diff;

  pop(cmd);
}

/**
 * divide - divides second top element of the stack with the top element of the stack
 *
 * @cmd: access to useful variables from command struct
 */

void divide(cmd_t *cmd)
{
  stack_t **h = cmd->head;
  stack_t *node_1 = NULL;
  stack_t *node_2 = NULL;
  int quotient = 0;

  if (h == NULL || *h == NULL || (*h)->next == NULL)
    {
      printf("L%d: can't div, stack too short\n", cmd->line_number);
      exit(EXIT_FAILURE);
    }

  if (node_1->n == 0)
    {
      printf("L%d: division by zero\n", cmd->line_number);
      exit(EXIT_FAILURE);
    }

  node_1 = *h;
  node_2 = (*h)->next;
  quotient = node_2->n / node_1->n;
  node_2->n = quotient;
  pop(cmd);
}

/**
 * mul - multiplies the second top element of the stack with the top element of the stack
 *
 * @cmd: access to useful variables from command struct
 */

void mul(cmd_t *cmd)
{
  stack_t **h = cmd->head;
  stack_t *node_1 = NULL;
  stack_t *node_2 = NULL;
  int product = 0;

  if (h == NULL || *h == NULL || (*h)->next == NULL)
    {
      printf("L%d: can't mul, stack too short\n", cmd->line_number);
      exit(EXIT_FAILURE);
    }
  
  node_1 = *h;
  node_2 = (*h)->next;

  product = node_2->n * node_1->n;
  node_2->n = product;

  pop(cmd);
}

/**
 * mod - computes the rest of the division of the second top element of the stack by the top element of the stack
 *
 * @cmd: access to useful variables from command struct
 */

void mod(cmd_t *cmd)
{
  stack_t **h = cmd->head;
  stack_t *node_1 = NULL;
  stack_t *node_2 = NULL;
  int rem = 0;

  if (h == NULL || *h == NULL || (*h)->next == NULL)
    {
      printf("L%d: can't mod, stack too short\n", cmd->line_number);
      exit(EXIT_FAILURE);
    }
  
  if (node_1->n == 0)
    {
      printf("L%d: division by zero\n", cmd->line_number);
      exit(EXIT_FAILURE);
    }

  node_1 = *h;
  node_2 = (*h)->next;

  rem = node_2->n % node_1->n;
  node_2->n = rem;

  pop(cmd);
}

/**
 * pchar - prints the char at the top of the stack, followed by a new line
 *
 * @cmd: access to specific data from command struct
 */

void pchar(cmd_t *cmd)
{
  stack_t *h = *cmd->head;

  if (h == NULL)
    {
      printf("L%d: can't pchar, stack empty\n", cmd->line_number);
      exit(EXIT_FAILURE);
    }
  
  if (h->n < 0 || h->n > 127)
    {
      printf("L%d: can't pchar, value out of range\n", cmd->line_number);
      exit(EXIT_FAILURE);
    }

  printf("%c\n", h->n);
}

/**
 * pstr - prints the string starting at the top of the stack
 *
 * @cmd: data specific variables for command
 */

void pstr(cmd_t *cmd)
{
  stack_t *h = *cmd->head;

  if (h == NULL)
      return;

  while (h != NULL && (h->n > 0 && h->n <= 127))
    {
      printf("%c", h->n);
      h = h->next;
    }
  putchar('\n');
}

/**
 * rotl - rotates the stack to the top
 *
 * @cmd: access to specific data from command struct
 */

void rotl(cmd_t *cmd)
{
  stack_t **h = cmd->head;
  stack_t *first = NULL;
  stack_t *second = NULL;
  stack_t *last = NULL;

  if (*h == NULL || h == NULL || (*h)->next == NULL)
    {
      printf("L%d: can't swap, stack too short\n", cmd->line_number);
      exit(EXIT_FAILURE);
    }

  first = *h;
  second = (*h)->next;
  last = *h;

  while (last->next != NULL)
    {
      last = last->next;
    }

  first->next = last->next;
  first->prev = last;
  last->next = first;
  second->prev = NULL;
  *h = second;
}

/**
 * rotr - rotates the stack to the bottom
 *
 * @cmd: access to specific data from command struct
 */

void rotr(cmd_t *cmd)
{
  stack_t **h = cmd->head;
  stack_t *first = NULL;
  stack_t *second = NULL;
  stack_t *last = NULL;

  if (*h == NULL || h == NULL || (*h)->next == NULL)
    {
      printf("L%d: can't swap, stack too short\n", cmd->line_number);
      exit(EXIT_FAILURE);
    }

  first = *h;
  second = *h;
  last = *h;

  while (last->next != NULL)
      last = last->next;

  while (second->next != last)
    second = second->next;

  last->next = first;
  last->prev = first->prev;
  first->prev = last;
  second->next = NULL;
  *h = last;
}
