/******************************************************************************
 * Copyright (C) 2023 by 0xObat
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.h
 * @brief Abstraction of basic data manipulation operations
 *
 * This header file provides an abstraction of basic
 * data manipulation operations via function calls. 
 *
 * @author 0xObat
 * @date March 6 2024
 *
 */
#ifndef __DATA_H__
#define __DATA_H__
#define BASE_2 2
#define BASE_3 3
#define BASE_4 4
#define BASE_5 5
#define BASE_6 6
#define BASE_7 7
#define BASE_8 8
#define BASE_9 9
#define BASE_10 10
#define BASE_11 11
#define BASE_12 12
#define BASE_13 13
#define BASE_14 14
#define BASE_15 15
#define BASE_16 16

/**
 * @brief Converts data from a standard integer type into an ASCII string
 *
 * Given an unsigned integer, a pointer to the adress where the ASCII string
 * is stored and the base of the integer, this will convert the unsigned
 * integer data from a a standard integer type into an ASCII string.
 *
 * @param data Signed number between -2,147,483,648 and 2,147,483,647 (inclusive)
 * @param ptr Pointer to address where data is stored
 * @param base Base of data between 2(0b) and 16(0x)
 *
 * @return An ASCII string of the length of the converted data(including the null terminator)
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converts data back from an ASCII represented string into an integer type
 *
 * Given a pointer to an ASCII string, the number of digits(including the 
 * null terminator) and the base to be converted into, this will convert
 * data back from an ASCII represented string into an integer type index
 * into that data set to the value provided.
 *
 * @param ptr Pointer n ASCII string
 * @param digits Length of the ASCII string (including the null terminator)
 * @param base Base of data between 2(0b) and 16(0x)
 *
 * @return The converted 32-bit signed integer.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */