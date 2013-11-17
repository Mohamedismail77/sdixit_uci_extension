/**
 ***********************************************************************
 * @preamble
 *   EECS 805 - C for Embedded Systems (Lab 1)
 *
 * @author
 *   Shreerang Dixit (shreerang.dixit@gmail.com)
 *
 * @file
 *   bitops.c
 *
 * @brief
 *   Utilities for bit manipulation.
 *
 ***********************************************************************
 */

#include <stdio.h>
#include <string.h>

#include "bitops.h"

#define BIT(n)    ((uint_t)1 << n)           /*< Value with the specified bit set*/
#define MAXVAL(n) (((uint_t)(1 << (n))) - 1) /*< Maximum value that is supported by 'n' number of bits*/

/**
 **********************************************
 * @brief
 * For a given 'old_val', sets 'width' number of bits
 * starting at 'pos' to the value specified by 'set_val'
 *
 * @param old_val value whose bits are to be set
 * @param pos     LSB position from which the bits are to be set
 * @param width   number of bits to set
 * @param set_val value to be set
 * @return        result, or the original value if an error occurred
 **********************************************
 **/
uint_t bits_set(uint_t old_val, int pos, int width, uint_t set_val)
{
  uint_t clear_mask = MAXVAL(width);
  uint_t result     = old_val;

  if ((pos + width) > (sizeof(uint_t) * 8))
  {
    printf("Invalid input: position (%d) and width (%d) cannot exceed %d bits\n", pos, width, (sizeof(uint_t) * 8));
  }
  else if (set_val > MAXVAL(width))
  {
    printf("Invalid input: set_val (%d) cannot exceed bit width of (%d)\n", set_val, width);
  }
  else
  {
    //Shift to ignore the bits after the desired LSB position
    set_val    = set_val << pos;
    clear_mask = ~(clear_mask << pos);

    //Clear the bits
    result &= clear_mask;

    //Set the bits
    result |= set_val;
  }

  return (result);
}

/**
 **********************************************
 * @brief
 * For a given 'old_val' inverts 'width' number
 * of bits starting at LSB position 'pos'
 *
 * @param old_val value to modify
 * @param pos     LSB position from which are inverted
 * @param width   number of bits to invert
 * @return        the result, or the original value if an error occurred
 **********************************************
 **/
uint_t bits_invert(uint_t old_val, int pos, int width)
{
  int    i      = 0;
  uint_t result = old_val;
  uint_t mask   = 0;

  if ((pos + width) > (sizeof(uint_t) * 8))
  {
    printf("Invalid input: position (%d) and width (%d) cannot exceed %d bits\n", pos, width, (sizeof(uint_t) * 8));
  }
  else
  {
    mask    = MAXVAL(width);
    mask    = mask << pos;
    result ^= mask;
  }

  return (result);
}

/**
 **********************************************
 * @brief
 * For a given 'old_val', XOR's 'width' number of bits
 * with the value specified by 'set_val', starting at 'pos'.
 *
 * @param old_val value whose bits are to be XOR'd
 * @param pos     LSB position from which the bits are to be set
 * @param width   number of bits to XOR
 * @param set_val value to be XOR'd with
 * @return        result, or the original value if an error occurred
 **********************************************
 **/
uint_t bits_xor(uint_t old_val, int pos, int width, uint_t set_val)
{
  uint_t set_mask = set_val;
  uint_t result   = old_val;

  if ((pos + width) > (sizeof(uint_t) * 8))
  {
    printf("Invalid input: position (%d) and width (%d) cannot exceed %d bits\n", pos, width, (sizeof(uint_t) * 8));
  }
  else if (set_val > MAXVAL(width))
  {
    printf("Invalid input: set_val (%d) cannot exceed bit width of (%d)\n", set_val, width);
  }
  else
  {
    //Shift the value to be xor'd to skip bits we want to avoid
    set_val = set_val << pos;

    //Set the bits
    result ^= set_val;
  }

  return (result);
}

