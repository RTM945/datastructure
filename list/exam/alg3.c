// 已知线性单链表中的元素以值递增有序排列，试写一个高效的算法，
// 删除表中所有介于（mink,maxk）的元素
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node* next;
} Node;

int append(Node* list, int data);

int print(Node* list);

int del(Node* list, int min, int max);

int append(Node* list, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        return 0;
    }
    node->data = data;
    node->next = NULL;
    Node* p = list;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = node;
    return 0;
}

int print(Node* list) {
    Node* p = list->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return 1;
}

int del(Node* list, int min, int max) {
    Node* p = list;
    while (p->next != NULL && p->next->data < min) {
        p = p->next;
    }
    Node* q = p->next;
    while (q != NULL && q->data <= max) {
        p->next = q->next;
        free(q);
        q = p->next;
    }
    return 1;
}

int main() {
    Node* list = (Node*)malloc(sizeof(Node));
    if (list == NULL) {
        return 0;
    }
    list->data = 0;
    list->next = NULL;
    for (int i = 0; i < 10; i++) {
        append(list, i);
        printf("append %d\n", i);
    }
    print(list);
    del(list, 2, 6);
    print(list);
    return 0;
}