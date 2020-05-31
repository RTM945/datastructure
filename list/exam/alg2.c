//单链表的就地逆置：利用原来的存储空间
//带头结点
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node* next;
} Node;

int append(Node* list, int data);

int print(Node* list);

int reverse(Node* list);

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

//本质上是把下一个节点插入L之后
int reverse(Node* list) {
    Node* p = list->next;
    list->next = NULL;
    while (p != NULL) {
        Node* q = p;
        p = p->next;
        q->next = list->next;
        list->next = q;
    }
    return 0;
}

int main() {
    Node* list = (Node*)malloc(sizeof(Node));
    if (list == NULL) {
        return 0;
    }
    list->data = 0;
    list->next = NULL;
    for (int i = 0; i < 5; i++) {
        append(list, i);
        printf("append %d\n", i);
    }
    print(list);
    reverse(list);
    print(list);
    return 0;
}
