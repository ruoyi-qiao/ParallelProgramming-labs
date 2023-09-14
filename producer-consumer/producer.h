#ifndef PRODUCER_H
#define PRODUCER_H

#define MAX_FILES 10
void producer_thread(int32_t tid, char* filename, Queue* q);

#endif
