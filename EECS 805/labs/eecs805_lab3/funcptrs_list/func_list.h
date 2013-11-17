/**
 ***********************************************************************
 * @preamble
 *   EECS 805 - C for Embedded Systems (Lab 3 - Part 2)
 *
 * @author
 *   Shreerang Dixit (shreerang.dixit@gmail.com)
 *
 * @file
 *   func_list.h
 *
 * @brief
 *   Linked list API that manages a collection of function pointers
 *
 ***********************************************************************
 */
#ifndef __FUNC_LIST_H__
#define __FUNC_LIST_H__

/*Type definition for the function pointer*/
typedef void (*messagefunc_t)();

/*Single item in a linked list*/
typedef struct node_s
{
  messagefunc_t  f;    /*< List item data (function pointer) */
  struct node_s *next; /*< Reference to the next node in list*/
}node_t;

/*Linked list structure*/
typedef struct func_list_s
{
  node_t *head;       /*< Beginning of the list*/
  node_t *tail;       /*< End of the list*/
  size_t  count;      /*< Number of items in the list*/
}func_list_t;

func_list_t *list_new();
void list_add(func_list_t *const list, const messagefunc_t func);
void list_invoke(const func_list_t *const list);
void list_free(func_list_t *list);


#endif