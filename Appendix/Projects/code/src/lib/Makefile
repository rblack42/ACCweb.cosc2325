LIB     = demolib
LIBDIR  = ../../libs
INCDIR  = ../../include
TARGET  = $(LIBDIR)/lib$(LIB).a

FILES   = $(wildcard *.cpp)
OBJS    = $(FILES:.cpp=.o)

CXX     = g++
RM      = rm -f
CFLAGS  = -Wall -I $(INCDIR)

# targets below ----------------------------------
all:    $(TARGET)

$(TARGET): $(OBJS)
		ar -rcs $(TARGET) $(OBJS)

%.o:    %.cpp
		$(CXX) $(CFLAGS) $(INCS) -c $< -o $@

clean:
		$(RM) $(OBJS) $(TARGET)

