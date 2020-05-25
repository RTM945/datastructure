// 已知一个线性链表表示的线性表中含有三类字符的数据元素（如字母、数字、和其他）
// 试编写算法将该线性链表分割为三个循环链表，其中每个循环链表表示的线性表中均只含一类字符。
// 要求：充分用原来的存储空间；
// 问题：如果要求建立3个单链表；也利用原来的存储空间
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    char data;
    struct _Node* next;
} Node;

typedef struct _LinkedList {
    Node* head;
} LinkedList;

LinkedList* linkedlist_new();

Node* node_new(char data);

int linkedlist_print(LinkedList* l);

int linkedlist_split(LinkedList* l, LinkedList* a, LinkedList* b, LinkedList* c);

LinkedList* linkedlist_new() {
    LinkedList* l = (LinkedList*)malloc(sizeof(LinkedList));
    if (l == NULL) {
        return NULL;
    }
    Node* head = node_new('^');
    if (head == NULL) {
        free(l);
        return NULL;
    }
    l->head = head;
    return l;
}

Node* node_new(char data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->next = NULL;
    node->data = data;
    return node;
}

int linkedlist_print(LinkedList* l) {
    Node* node = l->head;
    while (node != NULL) {
        printf("%c ", node->data);
        node = node->next;
    }
    printf("\n");
    return 0;
}

int linkedlist_split(LinkedList* l, LinkedList* a, LinkedList* b, LinkedList* c) {
    a = linkedlist_new();
    if (a == NULL) {
        return 0;
    }
    b = linkedlist_new();
    if (b == NULL) {
        return 0;
    }
    c = l;
    Node* na = a->head;
    Node* nb = b->head;
    Node* q = l->head;
    Node* p = l->head->next;
    while (p != NULL) {
        printf("q = '%c', p = '%c'\n", q->data, p->data);
        if ((p->data > 64 && p->data < 91) || (p->data > 96 && p->data < 123)) {
            q = p;
            p = p->next;
        } else if (p->data > 47 && p->data < 58) {
            q->next = p->next;
            na->next = p;
            na = na->next;
            p = q->next;
        } else {
            q->next = p->next;
            nb->next = p;
            nb = nb->next;
            p = q->next;
        }
    }
    na->next = a->head;
    nb->next = b->head;
    q->next = c->head;
    linkedlist_print(l);
    linkedlist_print(a);
    linkedlist_print(b);
    return 0;
}

int main() {
    LinkedList* l = linkedlist_new();
    Node* node = l->head;
    printf("%c\n", node->data);
    char cs[] = {'a', '0', '!', 'b', '1', '?', 'c', '2', '='};
    for (int i = 0; i < 9; i++) {
        node->next = node_new(cs[i]);
        node = node->next;
    }
    linkedlist_print(l);
    LinkedList a;
    LinkedList b;
    LinkedList c;
    linkedlist_split(l, &a, &b, &c);
    return 0;
}