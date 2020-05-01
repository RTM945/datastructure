typedef int Type;
typedef struct {
    Type data;
    struct Node* node;
} Node, LinkedList;

LinkedList* linkedlist_new();