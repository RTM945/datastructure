typedef int Type;
typedef struct _ArrayQueue {
    Type* datas;
    int length;
    int capacity;
    int head;
    int tail;
} ArrayQueue;

ArrayQueue* queue_new(int capacity);

int queue_offer(ArrayQueue* q, Type e);

int queue_poll(ArrayQueue* q, Type* e);