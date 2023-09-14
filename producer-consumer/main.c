#include "queue.h"
#include "consumer.h"
#include "producer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[]) {
    // 默认消费者和生产者数量都是0
    int num_consumers = 0;
    int num_producers = 0;
    char* filenames[MAX_FILES];
    int num_files = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-c") == 0) { // 消费者的数量
            if (i + 1 >= argc) {
                fprintf(stderr, "Missing argument after -c\n");
                return EXIT_FAILURE;
            }
            num_consumers = atoi(argv[i+1]);
            i++;
        } else if (strcmp(argv[i], "-p") == 0) { // 生产者的数量
            if (i + 1 >= argc) {
                fprintf(stderr, "Missing argument after -p\n");
                return EXIT_FAILURE;
            }
            num_producers = atoi(argv[i+1]);
            i++;
        } else {
            if (num_files >= MAX_FILES) { // 文件的数量
                fprintf(stderr, "Too many files\n");
                return EXIT_FAILURE;
            }
            filenames[num_files++] = argv[i];
        }
    }
    // 生产者的数量和文件的数量必须相等
    if (num_files != num_producers) {
        fprintf(stderr, "Number of files must match number of producers\n");
        fprintf(stderr, "Usage: %s [-c <num_consumers>] [-p <num_producers>] <file1> <file2> ... <fileN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // 初始化队列
    Queue q = { .head = 0, .tail = 0, .size = 0 };
    // 初始化消费者线程
    omp_set_num_threads(num_consumers + num_producers);
    printf("Running with %d producers and %d consumers\n", num_producers, num_consumers);
    #pragma omp parallel num_threads(num_consumers + num_producers)
    {
        int tid = omp_get_thread_num();
        printf("Thread %d\n", tid);
        if (tid < num_producers) { // 生产者线程
            producer_thread(tid, filenames[tid], &q);
        } else {                   // 消费者线程
            consumer_thread(tid - num_producers, &q);
        }
    }
    printf("Total words: %d\n", cnt);
    return EXIT_SUCCESS;
}
