/**
 ***********************************************************************
 * @preamble
 *   EECS 805 - C for Embedded Systems (Lab 1)
 *
 * @author
 *   Shreerang Dixit (shreerang.dixit@gmail.com)
 *
 * @file
 *   bitops.h
 *
 * @brief
 *   Utilities for bit manipulation
 *
 ***********************************************************************
 */
#ifndef __BITOPS_H__
#define __BITOPS_H__

typedef unsigned int uint_t;

/*Macro shortcuts for bit manipulation functions*/
#define SETBITS(OLD_VAL, POS, WIDTH, SET_VAL) (((OLD_VAL) & ~(((uint_t)(1 << (WIDTH)) - 1) << POS)) | (SET_VAL << POS))
#define INVBITS(OLD_VAL, POS, WIDTH)          (OLD_VAL ^ (((uint_t)(1 << (WIDTH)) - 1) << POS))
#define XORBITS(OLD_VAL, POS, SET_VAL)        (OLD_VAL ^ (SET_VAL << POS))

uint_t bits_set(uint_t old_val, int pos, int width, uint_t set_val);
uint_t bits_invert(uint_t old_val, int pos, int width);
uint_t bits_xor(uint_t old_val, int pos, int width, uint_t set_val);


#endif