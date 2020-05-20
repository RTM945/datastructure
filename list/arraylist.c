#include "arraylist.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ArrayList* arraylist_new() {
    ArrayList* arraylist = (ArrayList*)malloc(sizeof(ArrayList));
    if (arraylist == NULL) {
        return NULL;
    }

    arraylist->data = malloc(sizeof(ArrayListElem) * ARRAYLIST_INIT_CAPACITY);
    if (arraylist->data == NULL) {
        free(arraylist);
        return NULL;
    }
    arraylist->length = 0;
    arraylist->capacity = ARRAYLIST_INIT_CAPACITY;
    return arraylist;
}

int arraylist_insert(ArrayList* l, int i, ArrayListElem e) {
    if (i < 0 || i > l->length) {
        return 0;
    }
    //扩容
    if (l->length + 1 > l->capacity) {
        int capacity = l->capacity * 2;
        ArrayListElem* data = realloc(l->data, sizeof(ArrayListElem) * capacity);
        if (data == NULL) {
            return 0;
        }
        l->data = data;
        l->capacity = capacity;
    }
    memmove(&l->data[i + 1],
            &l->data[i],
            (l->length - i) * sizeof(ArrayListElem));
    // ArrayListElem* p = &l->data[i];
    // ArrayListElem* q = &l->data[l->length - 1];
    // for (; p < q; q--) {
    //     *(p + 1) = *p;
    // }
    // *p = e;
    l->data[i] = e;
    l->length += 1;
    return 1;
}

int arraylist_delete(ArrayList* l, int i, ArrayListElem* e) {
    if (i < 0 || i > l->length - 1) {
        return 0;
    }
    *e = l->data[i];
    memmove(&l->data[i],
            &l->data[i + 1],
            (l->length - (i + 1)) * sizeof(ArrayListElem));
    // ArrayListElem* p = &l->data[i];
    // ArrayListElem* q = &l->data[l->length - 1];
    // for (; p < q; p++) {
    //     *p = *(p + 1);
    // }
    l->length -= 1;
    return 1;
}

int arraylist_get(ArrayList* l, int i, ArrayListElem* e) {
    if (i < 0 || i > l->length - 1) {
        return 0;
    }
    *e = l->data[i];
    return 1;
}

int arraylist_clear(ArrayList* l) {
    l->length = 0;
}

int arraylist_free(ArrayList* l) {
    free(l->data);
    free(l);
}

void arraylist_print(ArrayList* l) {
    int i;
    for (i = 0; i < l->length; i++) {
        // printf("%d ", l->data[i]);
        ArrayListElem e;
        arraylist_get(l, i , &e);
        printf("%d ", e);
    }
    printf("\n");
}

int main() {
    ArrayList* l = arraylist_new();
    int i;
    ArrayListElem e;
    for (i = 0; i < 20; i++) {
        arraylist_insert(l, i, i);
    }
    arraylist_print(l);
    arraylist_insert(l, 0, 10);
    arraylist_get(l, 0, &e);
    printf("%d \n", e);
    arraylist_print(l);
    arraylist_delete(l, 0, &e);
    printf("%d \n", e);
    arraylist_print(l);
    arraylist_clear(l);
    arraylist_print(l);
    return 0;
}
