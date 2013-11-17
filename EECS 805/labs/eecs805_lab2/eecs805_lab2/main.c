/**
 ***********************************************************************
 * @preamble
 *   EECS 805 - C for Embedded Systems (Lab 2)
 *
 * @author
 *   Shreerang Dixit (shreerang.dixit@gmail.com)
 *
 * @file
 *   main.c
 *
 * @brief
 *   Routines for byte boundary allocation/deallocation
 *
 ***********************************************************************
 */
#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint32_t;

/*Test struct*/
typedef struct
{
  char a[64];
}mystruct_t;

/**
 **********************************************
 * @brief
 * Given a 'size', allocates a memory block so it's a
 * multiple of the specified byte 'boundary'
 *
 * @param size           the total bytes to allocate
 * @param boundary       the byte boundary to align the bytes to
 * @return               'boundary' byte aligned memory
 **********************************************
 **/
void *alloc(size_t size, size_t boundary)
{
  uint32_t *begin = NULL;
  uint32_t *end   = NULL;
  char     *tmp   = NULL;

  begin = (uint32_t *)malloc(size + boundary);

  if (begin == NULL)
  {
    printf("Fatal error allocating memory. Exiting...");
    exit(EXIT_FAILURE);
  }

  printf("ORIGINAL PTR: [0x%X]\n", begin);

  end = begin;
  tmp = (char *)end; /*Cast to char* so the pointer can be incremented one byte at a time*/

  while ((((uint32_t)tmp) % boundary) != 0)
  {
    tmp++;
  }

  end = (uint32_t *)tmp;
  printf("%d BYTE ALIGNED PTR: [0x%X]\n", boundary, end);
  end--;
  printf("ORIGINAL PTR: [0x%X] stored at [0x%X]\n", begin, end);
  *end = ((uint32_t)begin);
  end++;
  printf("%d BYTE ALIGNED PTR: [0x%X]\n", boundary, end);
  return (end);
}

/**
 **********************************************
 * @brief
 * Deallocates a byte aligned memory block that was
 * allocated by the 'alloc()' function
 *
 * @param p pointer to the memory to deallocate
 **********************************************
 **/
void dealloc(void *p)
{
  uint32_t *pAligned = (uint32_t *)p;

  pAligned--;
  printf("DEALLOC ORIGINAL PTR: [0x%X]...", (*pAligned));
  free((uint32_t *)(*pAligned));
  printf("OK\n");
}

/**
 **********************************************
 * @brief
 * Main entry point for the test application
 *
 * @return EXIT_SUCCESS
 **********************************************
 **/
int main()
{
  mystruct_t *mystuff;

  printf("\nAllocating 128 byte aligned memory block\n");
  printf("----------------\n");
  mystuff = (mystruct_t *)alloc(sizeof(mystruct_t), 128);
  printf("\nDeallocating the memory block\n");
  printf("----------------\n");
  dealloc(mystuff);
  return (EXIT_SUCCESS);
}