CC = mpic++

CFLAGS = -Wall 

TARGET = odd_even_sort

SRCS = main.cpp utils.cpp

HEADERS = utils.hpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)
