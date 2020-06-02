#include "array_queue.h"

#include <stdio.h>
#include <stdlib.h>

ArrayQueue* queue_new(int capacity) {
    ArrayQueue* q = (ArrayQueue*)malloc(sizeof(ArrayQueue));
    if (q == NULL) {
        return NULL;
    }
    q->datas = (Type*)malloc(sizeof(Type) * capacity);
    if (q->datas == NULL) {
        free(q);
        return NULL;
    }
    q->capacity = capacity;
    q->head = 0;
    q->tail = 0;
    q->length = 0;
    return q;
}

int queue_offer(ArrayQueue* q, Type e) {
    if ((q->tail + 1) % q->capacity == q->head) {
        return 0;
    }
    q->datas[q->tail] = e;
    q->tail = (q->tail + 1) % q->capacity;
    q->length++;
    return 1;
}

int queue_poll(ArrayQueue* q, Type* e) {
    if (q->head == q->tail) {
        return 0;
    }
    *e = q->datas[q->head];
    q->head = (q->head + 1) % q->capacity;
    q->length--;
    return 1;
}

int queue_print(ArrayQueue* q) {
    for (int i = q->head; i != q->tail; i = (i + 1) % q->capacity) {
        printf("%d ", q->datas[i]);
    }
    printf("\n");
    return 1;
}

int main() {
    ArrayQueue* q = queue_new(5);
    for (int i = 0; i < 5; i++) {
        queue_offer(q, i);
        printf("offer %d\n", i);
        queue_print(q);
    }
    for (int i = 0; i < 5; i++) {
        Type e;
        queue_poll(q, &e);
        printf("poll %d\n", e);
        queue_print(q);
    }
    return 0;
}