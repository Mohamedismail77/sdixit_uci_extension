/**
 ***********************************************************************
 * @preamble
 *   EECS 805 - C for Embedded Systems (Lab 3 - Part 2)
 *
 * @author
 *   Shreerang Dixit (shreerang.dixit@gmail.com)
 *
 * @file
 *   func_list.c
 *
 * @brief
 *   Linked list that manages a collection of function pointers
 *
 ***********************************************************************
 */
#include <stdlib.h>
#include <stdio.h>

#include "func_list.h"

/**
 **********************************************
 * @brief
 * Allocates memory for a new func_list_t instance
 *
 * @return pointer to a new func_list_t
 **********************************************
 **/
func_list_t *list_new()
{
  func_list_t *ret = NULL;

  ret = (func_list_t *)malloc(sizeof(func_list_t));

  if (ret == NULL)
  {
    printf("malloc() error\n");
    exit(EXIT_FAILURE);
  }

  ret->head  = NULL;
  ret->tail  = NULL;
  ret->count = 0;

  return (ret);
}

/**
 **********************************************
 * @brief
 * Adds a function pointer of type messagefunc_t
 * to the linked list
 *
 * @param list the list to add the function pinter to
 * @param func the function pointer to be added
 **********************************************
 **/
void list_add(func_list_t *const list, const messagefunc_t func)
{
  node_t *node = NULL;

  node = (node_t *)malloc(sizeof(node_t));

  if (node == NULL)
  {
    printf("malloc() error\n");
    exit(EXIT_FAILURE);
  }

  node->f    = func;
  node->next = NULL;

  /*The list is empty. Add first element*/
  if (list->head == NULL)
  {
    list->head = list->tail = node;
  }
  else /*The list is not empty. Append element to the end*/
  {
    list->tail->next = node;
    list->tail       = list->tail->next;
  }

  list->count++;
}

/**
 **********************************************
 * @brief
 * Invokes all function pointers stored in the
 * specified list.
 *
 * @param list the list to execute the funtions in
 **********************************************
 **/
void list_invoke(const func_list_t *const list)
{
  node_t *node = list->head;

  while (node != NULL)
  {
    (node->f)();
    node = node->next;
  }
}

/**
 **********************************************
 * @brief
 * Deallocates memory for a list
 *
 * @param list the list to be deallocated
 **********************************************
 **/
void list_free(func_list_t *list)
{
  node_t *node = list->head;
  node_t *tmp  = list->head;

  /*Free list node*/
  while (tmp != NULL)
  {
    /*Move to next item before freeing up the previous one*/
    node = node->next;
    free(tmp);
    tmp = node;
  }

  /*Free the list structure*/
  free(list);
}

