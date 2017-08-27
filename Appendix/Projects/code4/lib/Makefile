# Makefile to build project library
LIBNAME =   demolib

# source files
FILES   = $(wildcard *.cpp)

# generated files
OBJS    = $(FILES:.cpp=.o)

# tools we use here
CXX     = g++
AR      = ar
RM      = rm -f

# header files live here
INCDIR  = ../include

# targets follow ---------------------------------
all:    lib$(LIBNAME).a

clean:
		$(RM) $(OBJS) lib$(LIBNAME).a

lib$(LIBNAME).a:    $(OBJS)
		$(AR) -rcs $@ $^

# implicit rules follow -----------------
%.o:    %.cpp
		$(CXX) -c -I $(INCDIR) $< -o $@


