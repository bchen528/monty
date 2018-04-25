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
	printf("L%d: can't pop an empty stack", cmd->line_number);
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
  stack_t * second = NULL;

  if (*h == NULL || h == NULL || (*h)->next == NULL || (*h)->next->next == NULL)
    {
      printf("L%d: can't swap, stack too short", cmd->line_number);
      exit(EXIT_FAILURE);
    }
  first = *h;
  second = (*h)->next;

  second->next = first;
  first->next = second->next;
  (second->next)->prev = first;
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

  if (*h == NULL || h == NULL || (*h)->next == NULL || (*h)->next->next == NULL)
    {
      printf("L%d: can't add, stack too short", cmd->line_number);
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

  if (*h == NULL || h == NULL || (*h)->next == NULL || (*h)->next->next == NULL)
    {
      printf("L%d: can't add, stack too short", cmd->line_number);
      exit(EXIT_FAILURE);
    }
  
  node_1 = *h;
  node_2 = (*h)->next;

  diff = node_2->n - node_1->n;
  node_2->n = diff;

  pop(cmd);
}
