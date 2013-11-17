/**
 ***********************************************************************
 * @preamble
 *   EECS 805 - C for Embedded Systems (Lab 3 - Part 1)
 *
 * @author
 *   Shreerang Dixit (shreerang.dixit@gmail.com)
 *
 * @file
 *   main.c
 *
 * @brief
 *   Test an array of function pointers
 *
 ***********************************************************************
 */
#include <stdio.h>
#include <stdlib.h>

/*Type definition for the function pointer*/
typedef void (*messagefunc_t)();

/*Test functions*/
static void m1();
static void m2();

/*Array of function pointers to test functions m1() and m2()*/
static messagefunc_t msg_printers[2] = {m1, m2};

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
  int i = 0;
   /*Invoke all function pointers stored in the array*/
  for (i = 0; i < (sizeof(msg_printers) / sizeof(msg_printers[0])); i++)
  {
    (msg_printers[i])();
  }

  return (EXIT_SUCCESS);
}

/****************Begin Test Functions****************/
static void m1()
{
  printf("Hello");
}

static void m2()
{
  printf(" World\n");
}
/****************End Test Functions****************/
