#include "queue.h"

int32_t get_size(Queue* q) {
    return q->size;
}
/*
 * enqueue和dequeue函数使用的都是同一个临界区，保证了队列的线程安全性
 * 和课上的例子不太一样，课上的每个队列只会有一个线程进行出队操作，此处会出现出队的线程竞争
 */ 
void enqueue(Queue* q, char* line) {
    if(get_size(q) == MAX_QUEUE_SIZE) {
        fprintf(stderr, "Queue is full\n");
        return;
    }
    // 入队临界区
    #pragma omp critical
    {
        strcpy(q->lines[q->tail], line);
        q->tail = (q->tail + 1) % MAX_QUEUE_SIZE;
        q->size++;
    }
}

int8_t dequeue(Queue* q, char* line) {
    int8_t success = 0;
    if(get_size(q) == 0) {
        return success;
    }
    // 出队临界区
    #pragma omp critical
    {
        strcpy(line, q->lines[q->head]);
        q->head = (q->head + 1) % MAX_QUEUE_SIZE;
        q->size = q->size - 1;
        success = 1;
    }
    return success;
}
