TARGET	= lexer
FILES	= $(TARGET).cpp
OBJS	= $(FILES:.cpp=.o)

all:	lexer

$(TARGET):	$(OBJS)
		g++ $^ -o $@

%.o:	%.cpp
		g++ -c $^ -o $@

clean:
		rm $(TARGET) $(OBJS)

