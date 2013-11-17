/**
 ***********************************************************************
 * @preamble
 *   EECS 805 - C for Embedded Systems (Lab 3 - Part 2)
 *
 * @author
 *   Shreerang Dixit (shreerang.dixit@gmail.com)
 *
 * @file
 *   main.c
 *
 * @brief
 *   Test driver for the function pointer list
 *
 ***********************************************************************
 */
#include <stdio.h>
#include <stdlib.h>

#include "func_list.h"

/*Test functions*/
static void m1();
static void m2();
static void m3();
static void m4();

/**
 **********************************************
 * @brief
 * Application entry point
 *
 * @return EXIT_SUCCESS
 **********************************************
 **/
int main()
{
  /*Create new linked list*/
  func_list_t *list = list_new();

  /*Add function pointers to linked list*/
  list_add(list, m1);
  list_add(list, m2);
  list_add(list, m3);
  list_add(list, m4);

  /*Invoke all function pointers stored in list*/
  list_invoke(list);

  /*Free the linked list*/
  list_free(list);

  return (EXIT_SUCCESS);
}

/****************Begin Test Functions****************/
static void m1()
{
  printf("Never gonna give you up\n");
}

static void m2()
{
  printf("Never gonna let you down\n");
}

static void m3()
{
  printf("Never gonna run around...");
}

static void m4()
{
  printf("and desert you\n");
}
/****************End Test Functions****************/
