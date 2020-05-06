typedef void* Type;
typedef struct _Node {
    Type data;
    struct _Node* next;
} Node;

typedef struct _LinkedList {
    int length;
    struct _Node* head;
} LinkedList;

LinkedList* linkedlist_new();

Node* node_new(Type e);

int linkedlist_insert(LinkedList* l, int index, Type e);

int linkedlist_delete(LinkedList* l, int index, Type* e);

int linkedlist_free(LinkedList* l);

int linkedlist_get(LinkedList* l, int index, Type* e);