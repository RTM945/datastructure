#include "array_stack.h"

#include <stdio.h>
#include <stdlib.h>

Stack* stack_new(int capacity) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if (s == NULL) {
        return NULL;
    }
    s->datas = (Type*)malloc(capacity * sizeof(Type));
    if (s->datas == NULL) {
        free(s);
        return NULL;
    }
    s->top = s->datas;
    s->length = 0;
    s->capacity = capacity;
    return s;
}

int stack_push(Stack* s, Type e) {
    if (s->length + 1 > s->capacity) {
        int capacity = s->capacity * 2;
        Type* datas = realloc(s->datas, sizeof(Type) * capacity);
        if (datas == NULL) {
            return 0;
        }
        s->datas = datas;
        s->top = s->datas + s->length;
        s->capacity = capacity;
    }
    *s->top++ = e;
    // s->datas[s->length] = e;
    // s->top = &s->datas[s->length];
    s->length++;
    return 1;
}

int stack_pop(Stack* s, Type* e) {
    if (s->datas == s->top) {
        return 0;
    }
    *e = *--s->top;
    s->length--;
    return 1;
}

int stack_clear(Stack* s) {
    s->length = 0;
    s->top = s->datas;
}

int stack_free(Stack* s) {
    free(s->datas);
    free(s);
}

int stack_isempty(Stack* s) {
    return s->datas == s->top;
}

int stack_print(Stack* s) {
    for (int i = 0; i < s->length; i++) {
        printf("%d ", s->datas[i]);
    }
    printf("\n");
    return 0;
}

int main() {
    Stack* s = stack_new(10);
    for (int i = 0; i < 20; i++) {
        printf("push %d\n", i);
        stack_push(s, i);
        stack_print(s);
    }
    while (!stack_isempty(s)) {
        Type e;
        stack_pop(s, &e);
        printf("pop %d\n", e);
        stack_print(s);
    }
    stack_free(s);
    return 0;
}