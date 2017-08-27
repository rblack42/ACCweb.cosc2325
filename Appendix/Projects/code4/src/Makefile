# Makefile for primary application

TARGET  = example

# tools we will use
CXX     = g++
RM      = rm -f

# define the list of source files
FILES   = $(wildcard *.cpp)

# libraries we will need 
LIBDIR  = ../lib
LIB     = demolib
LIBC    = -L $(LIBDIR) -l$(LIB)

# generated files (cleaned)
OBJS    = $(FILES:.cpp=.o)

# header files live here
INCDIR  = ../include

# targets follow ---------------------------
all:    $(TARGET)

$(TARGET):  $(OBJS)
		$(CXX) -o $(TARGET) $(OBJS) $(LIBC)

clean:
		$(RM) $(TARGET) $(OBJS)

run:    $(TARGET)
		./$(TARGET)

# implicit rules follow---------------------
%.o:    %.cpp
		$(CXX) -c -I $(INCDIR) $< -o $@



