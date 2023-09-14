#include "queue.h"
#include "consumer.h"

void consumer_thread(int32_t tid, Queue* q) {
    char line[MAX_LINE_LENGTH];
    char* saveptr;
    // 将读入的一行的每个单词都分解出来
    for(;;) {
        if(dequeue(q, line) == 0) { // 队列为空
            break;
        }
        printf("Consumer %d: %s\n", tid, line);
        char* word = strtok_r(line, " \t\n", &saveptr); // 分解出第一个单词 
        while(word != NULL) {
            cnt++;
            printf("Consumer %d: %s\n", tid, word);
            printf("line\t= %s\n", line);
            printf("saveptr\t= %s\n", saveptr);
            word = strtok_r(NULL, " \t\n", &saveptr); // 分解出下一个单词
        }
    }
}