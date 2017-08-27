# Makefile to build application

TARGET  = example
PGM_LIB = demolib

FILES   = $(wildcard *.cpp)
OBJS    = $(FILES:.cpp=.o)

CXX     = g++

INC_DIR = ../include
LIB_DIR = ../libs
LIB     = $(LIB_DIR)/lib$(PGM_LIB).a

CFLAGS  = -Wall -I $(INC_DIR)
LDFLAGS = -L $(LIB_DIR) -l$(PGM_LIB)

all:    $(TARGET)
		echo "building program"

$(TARGET):  $(OBJS) $(LIB)
		$(CXX) -o $(TARGET) $(LDFLAGS) $(OBJS)

$(LIB):
		$(MAKE) -C lib all
clean:
		echo "deleting unneeded files"
		$(RM) $(OBJS)
		$(MAKE) -C lib clean

%.o:    %.cpp
		$(CXX) $(CFLAGS) -c $< -o $@
