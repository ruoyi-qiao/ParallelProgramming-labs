# 生产者-消费者模型课后作业

该程序包含多个线程，其中一部分线程为生产者，另一部分线程为消费者。每个生产者线程从不同的文件中读取文本行，并将其插入到一个共享的队列中。每个消费者线程从共享队列中获取文本行，并对其进行分词，将单词输出到stdout中。

## 依赖

* OpenMP
* gcc

## 编译

```bash
$ make
```
该命令将生成一个名为`producer_consumer`的可执行文件。

```bash
$ make clean
```
该命令将删除编译生成的文件。

## 运行

```bash
./producer_consumer [-p <num_producers>] [-c <num_consumers>] <file1> <file2> ...<fileN>
```
eg.
```bash
./producer_consumer -c 8 -p 4 file/Road.txt file/Night.txt file/Love.txt file/Woods.txt
```
![image.png](https://s2.loli.net/2023/05/15/QfsEuP1hDR3ie4F.png)

其中，file1 至 fileN (N<=10)为输入文件的路径且文件数量与生产者数量需要相同。程序将从这些文件中读取文本行，并将其插入到共享队列中，然后启动多个消费者线程从队列中获取文本行进行分词。

## 文件组织

* `main.c`：主函数，包含命令行参数解析、线程创建、线程同步等。
* `main.c`：包含主函数以及创建和启动生产者和消费者线程的代码。
* `producer.c`和`producer.h`：实现生产者线程的代码。
* `consumer.c`和`consumer.h`：实现消费者线程的代码。
* `queue.c`和`queue.h`：实现共享队列的实现，包含队列的初始化、入队、出队等。

10215101483 乔若奕