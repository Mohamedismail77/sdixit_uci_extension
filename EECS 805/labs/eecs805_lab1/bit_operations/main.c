/**
 ***********************************************************************
 * @preamble
 *   EECS 805 - C for Embedded Systems (Lab 1)
 *
 * @author
 *   Shreerang Dixit (shreerang.dixit@gmail.com)
 *
 * @file
 *   main.c
 *
 * @brief
 *   Test harness for lab 1
 *
 ***********************************************************************
 */
#include <stdio.h>

#include "bitops.h"

/**
 **********************************************
 * @brief
 * Tests the bits_set() function and macro.
 *
 * @param old_val value whose bits are to be set
 * @param pos     LSB position from which the bits are to be set
 * @param width   number of bits to set
 * @param set_val value to be set
 **********************************************
 **/
void test_bits_set(uint_t old_val, int pos, int width, uint_t set_val)
{
  uint_t result = -1;

  printf("-----\n");
  printf("SET_BITS: Value %x. Setting %d bits to value %d starting at bit %d (LSB)\n", old_val, width, set_val, pos);
  result = bits_set(old_val, pos, width, set_val);
  printf("Result = %x (%s)\n", result, (result == SETBITS(old_val, pos, width, set_val)) ? "Pass" : "Fail");
}

/**
 **********************************************
 * @brief
 * Tests the bits_invert() function and macro.
 *
 * @param old_val value to modify
 * @param pos     LSB position from which are inverted
 * @param width   number of bits to invert
 **********************************************
 **/
void test_bits_invert(uint_t old_val, int pos, int width)
{
  uint_t result = -1;

  printf("-----\n");
  printf("INV_BITS: Value %x. Inverting %d bits starting at bit %d (LSB)\n", old_val, width, pos);
  result = bits_invert(old_val, pos, width);
  printf("Result = %x (%s)\n", result, (result == INVBITS(old_val, pos, width)) ? "Pass" : "Fail");
}

/**
 **********************************************
 * @brief
 * Tests the bits_xor() function and macro.
 *
 * @param old_val value whose bits are to be XOR'd
 * @param pos     LSB position from which the bits are to be set
 * @param width   number of bits to XOR
 * @param set_val value to be XOR'd with
 **********************************************
 **/
void test_bits_xor(uint_t old_val, int pos, int width, uint_t set_val)
{
  uint_t result = -1;

  printf("-----\n");
  printf("XOR_BITS: Value %x. Xoring %d bits with value %d starting at bit %d (LSB)\n", old_val, width, set_val, pos);
  result = bits_xor(old_val, pos, width, set_val);
  printf("Result = %x (%s)\n", result, (result == XORBITS(old_val, pos, set_val)) ? "Pass" : "Fail");
}

/**
 **********************************************
 * @brief
 * Main entry point for application
 *
 * @return none
 **********************************************
 **/
int main()
{
  test_bits_set(0x0, 1, 3, 5);
  test_bits_set(0x54, 1, 3, 5);
  test_bits_set(0xffff, 1, 3, 7);
  test_bits_set(0xffff, 1, 3, 8);
  test_bits_set(0x75, 0, 2, 2);
  test_bits_invert(0x54, 1, 3);
  test_bits_invert(0x54, 10, 7);
  test_bits_invert(0x54, 0, 16);
  test_bits_invert(0x0, 0, 16);
  test_bits_xor(0x54, 1, 3, 5);
  test_bits_xor(0x54, 1, 3, 7);
  test_bits_xor(0x150, 0, 3, 7);
  test_bits_xor(0x256, 12, 4, 3);
  return (0);
}