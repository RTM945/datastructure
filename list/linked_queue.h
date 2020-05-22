typedef void* Type;
typedef struct _Node {
    Type data;
    struct _Node* next;
} Node;

typedef struct _LinkedQueue {
    int length;
    Node* head;
    Node* tail;
} LinkedQueue;

LinkedQueue* queue_new();

Node* node_new(Type e);

int queue_offer(LinkedQueue* q, Type e);

int queue_poll(LinkedQueue* q, Type* e);