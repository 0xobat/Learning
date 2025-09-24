# Sources
SOURCES = main.c \
		misc.c

# Linker file for MSP432
LINKER_FILE = -Tmsp432p401r.lds

CC = gcc
LDFLAGS = -Wl,-Map=main.map -L.$(LINKER_FILE)
CFLAGS = -Wall \
		-Werror \
        -g \
        -O0 \
        -std=c99

CPPFLAGS = -DMSP432 -I.
SIZE = size

TARGET = main

OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)
ASMS = $(SOURCES:.c=.asm)
PRES = $(SOURCES:.c=.i)

# Define rules to compile c files
%.o : %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

# Define rule to compile all .c file to .asm file
%.asm : %.c
	$(CC) -S $(CFLAGS) $(CPPFLAGS) $< -o $@

# Define rule to compile all .c file to .i file
%.i : %.c
	$(CC) -E $(CPPFLAGS) $< -o $@

# Define rule to compile all .c file to .d file
%.d : %.c
	$(CC) -E -M $(CPPFLAGS) $< -o $@

.PHONY: build
build: $(DEPS)
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@


.PHONY: clean
clean:
	rm -f *.i *.d *.map *.s *.out *.o