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
 * @file stats.h
 * @brief This is the header file for the statistics generator in stats.c
 *
 * @author 0xObat
 * @date 23-08-2023
 *
 */
#ifndef __STATS_H__
#define __STATS_H__


/**
 * @brief Print statistics including median, mean, maximum, and minimum.
 *
 * This function calculates and prints the median, mean, maximum, and minimum
 * values of the input array.
 *
 * @return It prints the calculated output statistcs.
 */
void print_statistics(unsigned char array[]);

/**
 * @brief Print elements of an array.
 *
 * This function prints the elements of the input array if the -DVERBOSE flag
 * is enables otherwise it does nothing.
 *
 * @param array The input array of unsigned characters.
 * @param size The size of the input array.
 * 
 * @return The inputed array.
 */
void print_array(unsigned char array[], int size);

/**
 * @brief Calculate the median of an array.
 *
 * This function calculates the median of the input array. If the size of the
 * array is even, it returns the average of the two middle elements.
 *
 * @param array The input array of unsigned characters.
 * @param size The size of the input array.
 * 
 * @return The median value.
 */
float find_median(unsigned char array[], int size);

/**
 * @brief Calculate the mean (average) of an array.
 *
 * This function calculates the mean (average) of the input array.
 *
 * @param array The input array of unsigned characters.
 * @param size The size of the input array.
 * 
 * @return The mean value.
 */
float find_mean(unsigned char array[], int size);

/**
 * @brief Find the maximum value in an array.
 *
 * This function finds and returns the maximum value in the input array.
 *
 * @param array The input array of unsigned characters.
 * @param size The size of the input array.
 * 
 * @return The maximum value.
 */
int find_maximum(unsigned char array[], int size);

/**
 * @brief Find the minimum value in an array.
 *
 * This function finds and returns the minimum value in the input array.
 *
 * @param array The input array of unsigned characters.
 * @param size The size of the input array.
 * 
 * @return The minimum value.
 */
int find_minimum(unsigned char array[], int size);

/**
 * @brief Sort an array from largest to smallest.
 *
 * This function sorts the input array in descending order (from largest to
 * smallest).
 *
 * @param array The input array of unsigned characters.
 * @param size The size of the input array.
 * 
 */
void sort_array(unsigned char array[], int size);

#endif /* __STATS_H__ */