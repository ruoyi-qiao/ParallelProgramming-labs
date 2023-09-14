#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <sys/types.h>
#include <omp.h>
#ifndef _OPENMP
#include <omp.h>
#define _OPENMP
#endif


#define MAX_LINE_LENGTH 1024
#define MAX_QUEUE_SIZE 1000


typedef struct {
    char lines[MAX_QUEUE_SIZE][MAX_LINE_LENGTH];
    int32_t head;
    int32_t tail;
    int32_t size;
} Queue;
int32_t cnt;
int32_t get_size(Queue* q);
void enqueue(Queue* q, char* line);
int8_t dequeue(Queue* q, char* line);



