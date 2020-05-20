typedef int Type;
typedef struct _Stack {
    Type* datas;
    Type* top;
    int length;
    int capacity;
} Stack;

Stack* stack_new(int capacity);

int stack_push(Stack* s, Type e);

int stack_pop(Stack* s, Type* e);

int stack_clear(Stack* s);

int stack_free(Stack* s);

int stack_isempty(Stack* s);