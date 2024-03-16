#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# This Makefile is designed to build an embedded software project for either
# the HOST or MSP432 platform. It includes targets for compiling, assembling,
# linking, and cleaning the project. The user can choose the target platform
# by setting the PLATFORM variable (HOST or MSP432) in the make command.
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      build: Compiles and links the project into an executable.
#      compile-all: Compiles all source files into object files.
#      clean: Removes all generated files.
#
# Platform Overrides:
#      PLATFORM: Set this variable to HOST or MSP432 to choose the target platform.
#
#------------------------------------------------------------------------------

# Platform Overrides
PLATFORM = HOST
include sources.mk

COURSE = COURSE1

# Target Executable
TARGET = course1
BUILD_DIR = build
# General Flags
FLAGS = -Wall \
		-Werror \
        -g \
        -O0 \
        -std=c99

# Compiler Flags for Host platform
ifeq ($(PLATFORM),HOST)
    CC = gcc
    CFLAGS = $(FLAGS)
    CPPFLAGS = -DHOST $(INCLUDES)
    LDFLAGS = -Wl,-Map=$(BUILD_DIR)/$(TARGET).map
    SIZE = size
endif

# Compiler Flags and Architectures Specific Flags for MSP432
ifeq ($(PLATFORM),MSP432)
    CC = arm-none-eabi-gcc
    LINKER_FILE = -Tmsp432p401r.lds
    CPU = -mcpu=cortex-m4
    ARCH = -march=armv7e-m
    SPECS = -specs=nosys.specs
    OTHER_FLAGS = -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
    SOURCES = main.c \
			memory.c \
			interrupts_msp432p401r_gcc.c \
			startup_msp432p401r_gcc.c \
			system_msp432p401r.c
    CFLAGS = $(FLAGS) $(OTHER_FLAGS) $(CPU) $(ARCH) $(SPECS)
    CPPFLAGS = -DMSP432 $(INCLUDES)
    LD = -L../
    LDFLAGS = -Wl,-Map=(BUILD_DIR)/$(TARGET).map,$(LD) $(LINKER_FILE)
    SIZE = arm-none-eabi-size
endif

# Additional compiler flags
ifeq ($(COURSE),COURSE1)
	CPPFLAGS += -DCOURSE1
endif

ifeq ($(VERBOSE),VERBOSE)
	CPPFLAGS += -DVERBOSE
endif

# Define object files and dependencies
OBJS := $(patsubst ./src/%.c,$(BUILD_DIR)/%.o,$(SOURCES))
PRES := $(patsubst ./src/%.c,$(BUILD_DIR)/%.i,$(SOURCES))
DEPS := $(patsubst ./src/%.c,$(BUILD_DIR)/%.d,$(SOURCES))
ASMS := $(patsubst ./src/%.c,$(BUILD_DIR)/%.asm,$(SOURCES))

# Define rule to compile all .c file to .o file
$(BUILD_DIR)/%.o : src/%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

# Define rule to compile all .c file to .asm file
$(BUILD_DIR)/%.asm : src/%.c
	$(CC) -S $(CFLAGS) $(CPPFLAGS) $< -o $@

# Define rule to compile all .c file to .i file
$(BUILD_DIR)/%.i : src/%.c
	$(CC) -E $(CPPFLAGS) $< -o $@

# Define rule to compile all .c file to .d file
$(BUILD_DIR)/%.d : src/%.c
	$(CC) -E -M $(CPPFLAGS) $< -o $@

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: $(DEPS)
build: $(BUILD_DIR)/$(TARGET).out

$(BUILD_DIR)/$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

.PHONY: clean
clean:
	rm -rf $(OBJS) $(DEPS) $(ASMS) $(PRES) $(BUILD_DIR)/$(TARGET).out $(BUILD_DIR)/$(TARGET).map
