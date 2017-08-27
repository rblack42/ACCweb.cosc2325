# Makefile for C project

TARGET = test

FILES   =   $(wildcard *.c)
OBJS    =   $(FILES:.c=.o)
ASMS    = $(FILES:.c=.s)

# Tools
GCC     = gcc
RM      = rm -f

# Targets ---------------------------------------
all:    $(TARGET)

$(TARGET):  $(OBJS)
	$(GCC) -o $@  $^

asm:    $(ASMS)

clean:
	$(RM) $(TARGET) $(OBJS) $(ASMS)

# Implicit rules --------------------------------
%.o:    %.c
	$(GCC) -c $< -o $@

%.s:    %.c
	$(GCC) -S -masm=intel $< -o $@

