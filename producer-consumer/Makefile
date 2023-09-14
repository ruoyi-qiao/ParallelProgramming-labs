CC = gcc
CFLAGS = -std=c11 -g -Wall -Wextra -pthread -fopenmp
OBJECTS = main.o producer.o consumer.o queue.o
TARGET = producer_consumer

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

main.o: main.c producer.h consumer.h queue.h
	$(CC) $(CFLAGS) -c main.c

producer.o: producer.c producer.h queue.h
	$(CC) $(CFLAGS) -c producer.c

consumer.o: consumer.c consumer.h queue.h
	$(CC) $(CFLAGS) -c consumer.c

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c

clean:
	rm -f $(OBJECTS) $(TARGET)
