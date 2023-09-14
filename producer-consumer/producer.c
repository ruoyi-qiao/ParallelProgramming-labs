#include "queue.h"
#include "producer.h"
#include <assert.h>

// 
void producer_thread(int32_t tid, char* filename, Queue* q) {
    assert(tid < MAX_FILES);
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    char* line = NULL; 
    size_t len = 0;    // len是line的长度
    while(getline(&line, &len, fp) != -1) { // 读入一行
        assert(strlen(line) < MAX_LINE_LENGTH);
        char* item = (char*)malloc(strlen(line) + 1); // 为每个单词分配空间
        strncpy(item, line, strlen(line) + 1);        // 将一行的内容复制到item中
        enqueue(q, item);                             // 将item入队
        free(item);
    }
    fclose(fp);
}