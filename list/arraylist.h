typedef int ArrayListElem;
#define ARRAYLIST_INIT_CAPACITY 10

typedef struct {
    ArrayListElem* data;
    int length;
    int capacity;
} ArrayList;

ArrayList* arraylist_new();

//success 1 fail 0
int arraylist_insert(ArrayList* l, int i, ArrayListElem e);

int arraylist_delete(ArrayList* l, int i, ArrayListElem* e);

int arraylist_get(ArrayList* l, int i, ArrayListElem* e);

int arraylist_clear(ArrayList* l);

int arraylist_free(ArrayList* l);
