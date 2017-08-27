TARGET  = ../test_runner

LIB     = demolib
LIBS    = ../libs
LIBDEP  = $(LIBS)/lib$(LIB).a
LIBDIR  = ../src/lib
INCDIR  = ../include

# source files
SRCS    = $(wildcard *.cpp)
INCS    = $(wildcard $(INCDIR(/*.h)


# generated files
OBJS    = $(SRCS:.cpp=.o)
DEPS    =  make.dep

CXX     = g++
RM      = rm -f

CFLAGS  = -Wall -I$(INCDIR)
LDFLAGS = -L$(LIBS) -l$(LIB)
 
all:    $(TARGET)

$(TARGET):  $(OBJS) $(LIBDEP)
		$(CXX) -o $(TARGET) $(LDFLAGS) $(OBJS)

clean:
		$(RM) $(OBJS) $(TARGET)

$(LIBDEP):
		$(MAKE) -C $(LIBDIR)

dep:    $(DEPS)

$(DEPS):    $(SRCS) $(INCS)
    	$(CXX) -M $(CXXFLAGS) $(SRCS) > $(DEPS)

include $(DEPS)

# implicit targets-----------------------------
%.o:    %.cpp
		$(CXX) -c  $(CFLAGS) -o $@ $<

