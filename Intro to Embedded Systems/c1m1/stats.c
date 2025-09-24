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
 * @file stats.c 
 * @brief This is a statistics generator for a test arrary
 *
 * The program includes functions to find the minimum, maximum,
 * mean, median, and to sort the array.
 *
 * @author 0xObat
 * @date 23-08-2023
 *
 */


#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

/* Function declarations */
void print_statistics(unsigned char array[]);
void print_array(unsigned char array[], int size);
float find_median(unsigned char array[], int size);
float find_mean(unsigned char array[], int size);
int find_maximum(unsigned char array[], int size);
int find_minimum(unsigned char array[], int size);
void sort_array(unsigned char array[], int size);

void main() {
  // Define the test data array
  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Call the statistics printing function */
  print_statistics(test);
}

/* Function to print statistics for the given array */
void print_statistics(unsigned char test[]){
  if (SIZE <= 0) {
    // Handle the case where size is zero or negative
    printf("ERROR: empty arrary\n");
  }
  else{
    // Print the original array
    print_array(test, SIZE);
    printf("\n");
    
    // Sort the array and print it
    sort_array(test, SIZE);
    printf("Sorted Array:");
    for (int i = 0; i < SIZE; i++) {
      printf("%d ", test[i]);
    }
    printf("\n\n");

    // Calculate and print the median, mean, maximum, and minimum
    printf("Median: %.2f\n", find_median(test, SIZE) );
    printf("\n");
    printf("Mean: %.3f\n", find_mean(test, SIZE) );
    printf("\n");
    printf("Maximum: %d\n", find_maximum(test, SIZE) );
    printf("\n");
    printf("Minimum: %d\n", find_minimum(test, SIZE) );
  }
}

/* Function to print the elements of an array */
void print_array(unsigned char array[], int size){
  printf("Array elements: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

/* Function to find the median of an array */
float find_median(unsigned char array[], int size){
  int mid;
  if (size % 2 == 1){
    mid = size / 2;
    return array[mid];
  }
  else{
    mid = size / 2;
    return (double)(array[mid] + array[mid-1]) / 2;
  }
}

/* Function to find the mean (average) of an array */
float find_mean(unsigned char array[], int size){
  unsigned int total = 0;
  double mean = 0;  
  for (int i = 0; i < size; i++) {
    total += array[i];
  }
  mean = (double)total / size;
  return mean;
}

/* Function to find the maximum value in an array */
int find_maximum(unsigned char array[], int size){
  int max = 0;
  for (int i = 0; i < size; i++) {
    if (array[i] > max) max = array[i];
  }
  return max;
}

/* Function to find the minimum value in an array */
int find_minimum(unsigned char array[], int size){
  int min = array[0];
  for (int i = 0; i < size; i++) {
    if (array[i] < min) min = array[i];
  }
  return min;
}

/* Function to sort an array in descending order */
void sort_array(unsigned char array[], int size){
  int tmp = 0;
  for (int b = 0; b < size; b++){
    for (int i = 0; i < size; i++) {
      if (array[i] < array[i+1]){
        tmp = array[i+1];
        array[i+1] = array[i];
        array[i] = tmp;
      }
    }
  }
}