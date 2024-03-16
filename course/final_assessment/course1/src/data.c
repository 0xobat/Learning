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
 * This implementation file provides an abstraction of basic
 * data manipulation operations via function calls. 
 *
 * @author 0xObat
 * @date March 6 2024
 *
 */

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "data.h"
#include "memory.h"
#include "platform.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
	// Check for valid base range
	if (base < 2 || base >16){
		#ifdef VERBOSE
		PRINTF("ERROR: Invalid base");
		#endif
		return 0;
	}

	// Initialize variables
    uint8_t* start_ptr = ptr;
    int32_t quotient = data;
    uint32_t remainder;
    uint8_t length = 0;
    bool negative = false;

	// Handle negative numbers
	if (data < 0){
        negative = true;
        *ptr++ = '-';
        start_ptr = ptr;
        length++;
        quotient = data * -1; // Convert to positive
	}
    
    // Convert the number to the specified base
    do {
        remainder = quotient % base;
        quotient = quotient / base;
        // Convert remainder to ASCII character
        if (remainder < 10)
            *ptr++ = '0' + remainder;
        else
            *ptr++ = 'A' + remainder - 10;
        length++;
    } while (quotient != 0);
    
    // Reverse the string
    if (negative){    
        my_reverse(start_ptr, length - 1);        
    } else{
        my_reverse(start_ptr, length);
    }
    
    // Add null terminator
    *(ptr + length) = '\0';
    length++;
	
    return length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){

	// Check for valid base range
    if (base < 2 || base > 16){
        #ifdef VERBOSE
		PRINTF("ERROR: Invalid base");
		#endif
        return 0; // Invalid base
    }

    // Initialize variables
    int32_t result = 0;
    bool negative = false;

    // Check for negative sign
    if (*ptr == '-') {
        negative = true;
        ptr++;
        digits--;
    }

    // Convert the characters to the specified base
    while (digits > 0 && *ptr != '\0') {
        uint8_t digit_value;
        if (*ptr >= '0' && *ptr <= '9')
            digit_value = *ptr - '0';
        else if (*ptr >= 'A' && *ptr <= 'F')
            digit_value = *ptr - 'A' + 10;
        else if (*ptr >= 'a' && *ptr <= 'f')
            digit_value = *ptr - 'a' + 10;
        else
            break; // Invalid character, stop conversion

        // Check if the digit value is within the base
        if (digit_value >= base)
            break; // Invalid character for the specified base

        // Update the result
        result = result * base + digit_value;
        ptr++;
        digits--;
    }

    // Apply negative sign if necessary
    if (negative)
        result = result * -1;

    return result;
}