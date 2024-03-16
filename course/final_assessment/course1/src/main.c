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
 * @file main.h
 * @brief Implimentation of Abstraction of basic data manipulation operations
 *
 * This file provides an abstraction of basic data manipulation operations
 * through function calls.
 *
 * @author 0xObat
 * @date March 6 2024
 *
 */

#include "platform.h"
#include "memory.h"
#include "course1.h"

int main(void){
  #ifdef COURSE1
    course1();
  #endif
}