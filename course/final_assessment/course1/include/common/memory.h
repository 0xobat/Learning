/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author 0xObat
 * @date March 6 2024
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Move byte(s) from the source location to the destination
 *
 * Given a source(src) pointer, destination(dst) pointer and length of data,
 * this will move the data from the src location to the destination location.
 *
 * @param src Pointer to the source data
 * @param dst Pointer to the destination data
 * @param length size of the data to be moved
 *
 * @return Pointer to destination location
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copies byte(s) from the source location to the destination
 *
 * Given a source(src) pointer, destination(dst) pointer and length of data,
 * this will copy the data from the src location to the destination location.
 *
 * @param src Pointer to the source data
 * @param dst Pointer to the destination data
 * @param length Size of the data to be copied
 *
 * @return Pointer to destination location
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Sets byte(s) in the source location to a specified value
 *
 * Given a source(src) pointer, length of the data and value to be written,
 * this will write all locations of that memory to the given value.
 *
 * @param src Pointer to the source data
 * @param length Size of the data to be changed
 * @param value value to be set at the source location
 *
 * @return Pointer to source location
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Sets byte(s) in the source location to Zero(0)
 *
 * Given a source(src) pointer and length of the data,
 * this will write all locations of that memory to Zero(0).
 *
 * @param src Pointer to the source data
 * @param length Size of the data to be changed
 *
 * @return Pointer to source location
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverses the order of byte(s) in the source location
 *
 * Given a source(src) pointer and length in bytes,
 * this will reverse the order of all of the bytes.
 *
 * @param src Pointer to the source data
 * @param length Size of the data to be reversed
 *
 * @return Pointer to source location
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Reserves a length of byte(s)
 *
 * Given a length in bytes, this will reserve the bytes and return the 
 * destination pointer.
 *
 * @param length Size of the data to be reserved
 *
 * @return Pointer to memory if successful, or a Null Pointer if not successful
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Frees reserved memory at source location
 *
 * Given a source(src) pointer, this will free the dynamic memory allocation.
 *
 * @param src Source pointer to location
 *
 * @return void
 */
void free_words(uint32_t * src);

#endif /* __MEMORY_H__ */