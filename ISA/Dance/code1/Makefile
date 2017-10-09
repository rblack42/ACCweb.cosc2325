TARGET	:=	test
FILES 	=	$(wildcard *.cpp)
OBJS	=	$(FILES:.cpp=.o)

all:	$(TARGET)

run:	$(TARGET)
	./$(TARGET)

$(TARGET)::	$(OBJS)
	g++ -o $@ $^

%.o:	%.cpp
	g++ -c -o $@ $<

clean:
	rm -f *.o test

