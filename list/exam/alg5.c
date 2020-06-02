//利用循环队列编写求K阶Fabonacci数列中前n+1项(f0,f1,···,fn)的算法。
//要求：fn<=max,fn+1>max,其中max是某个约定的常数
//注意：循环队列的最大容量是K,结束时队列中应该存放的是数列的后k项。

#include <stdio.h>
#include <stdlib.h>

typedef struct _Queue {
    int* datas;
    int capacity;
    int length;
    int head;
    int tail;
} Queue;

Queue* queue_new(int capacity);

int queue_offer(Queue* q, int e);

int queue_poll(Queue* q, int* e);

int queue_print(Queue* q);

int fabonacci(int k, Queue* q, int max);

Queue* queue_new(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        return NULL;
    }
    // capacity = capacity + 1;
    int* datas = (int*)malloc(sizeof(int) * capacity);
    if (datas == NULL) {
        free(q);
        return NULL;
    }
    q->datas = datas;
    q->head = 0;
    q->tail = 0;
    q->capacity = capacity;
    q->length = 0;
    return q;
}

int queue_offer(Queue* q, int e) {
    if ((q->tail + 1) % q->capacity == q->head) {
        int i;
        queue_poll(q, &i);
        // return 0;
    }
    q->datas[q->tail] = e;
    q->tail = (q->tail + 1) % q->capacity;  //浪费一个空间作为循环结束标志
    q->length++;
    return 1;
}

int queue_poll(Queue* q, int* e) {
    if (q->head == q->tail) {
        return 0;
    }
    *e = q->datas[q->head];
    q->head = (q->head + 1) % q->capacity;
    q->length--;
    return 1;
}

int queue_print(Queue* q) {
    for (int i = q->head; i != q->tail; i = (i + 1) % q->capacity) {
        printf("%d ", q->datas[i]);
    }
    printf("\n");
    return 1;
}

int fabonacci(int k, Queue* q, int max) {
    q = queue_new(k);
    queue_offer(q, 0);
    queue_offer(q, 1);
    int sum = 1;
    while (sum < max) {
        queue_offer(q, sum);
        int i = (q->tail - 1 + k) % k;
        int j = (q->tail - 2 + k) % k;
        sum = q->datas[i] + q->datas[j];
    }
    queue_print(q);
    for (int i = 0; i < q->length; i++) {
        printf("%d ", q->datas[i]);
    }
    return 0;
}

int main() {
    // Queue* q = queue_new(5);
    // for (int i = 0; i < 10; i++) {
    //     queue_offer(q, i);
    //     printf("offer %d\n", i);
    //     queue_print(q);
    // }
    // for (int i = 0; i < 5; i++) {
    //     int e;
    //     queue_poll(q, &e);
    //     printf("poll %d\n", e);
    //     queue_print(q);
    // }
    Queue q;
    fabonacci(10, &q, 100);
    // queue_print(&q);
    return 0;
}