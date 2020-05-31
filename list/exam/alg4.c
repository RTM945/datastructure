//假设有两个按值递增有序排列的单链表A和B，
//编写算法归并A和B成C，使得C是按值递减有序排列（允许有值重复的结点），
//并且C利用A、B原来的结点空间。

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node* next;
} Node;

int append(Node* list, int data);

int print(Node* list);

int union2(Node* a, Node* b, Node* c);

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

//依次遍历，小的拿出来插入表头，并且指针向后移动
int union2(Node* a, Node* b, Node* c) {
    Node* p = a->next;
    Node* q = b->next;
    c = b;
    c->next = NULL;
    free(a);
    while (p != NULL && q != NULL) {
        Node* s;
        if (p->data <= q->data) {
            s = p;
            p = p->next;
        } else {
            s = q;
            q = q->next;
        }
        s->next = c->next;
        c->next = s;
    }
    //一个链表读完了另一个还没有
    if (q != NULL) {
        p = q;
    }
    while (p != NULL) {
        //按循序插入表头
        Node* s = p;
        p = p->next;
        s->next = c->next;
        c->next = s;
    }
    print(c);
    return 1;
}

int main() {
    Node* a = (Node*)malloc(sizeof(Node));
    if (a == NULL) {
        return 0;
    }
    a->data = 0;
    a->next = NULL;
    int as[] = {1, 3, 6, 7, 8, 9};
    for (int i = 0; i < 6; i++) {
        append(a, as[i]);
    }
    Node* b = (Node*)malloc(sizeof(Node));
    if (b == NULL) {
        return 0;
    }
    b->data = 0;
    b->next = NULL;
    int bs[] = {2, 4, 5};
    for (int i = 0; i < 3; i++) {
        append(b, bs[i]);
    }
    print(a);
    print(b);
    Node c;
    union2(a, b, &c);
}