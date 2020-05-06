#include "single_linkedlist.h"

#include <stdio.h>
#include <stdlib.h>

LinkedList* linkedlist_new() {
    LinkedList* l = (LinkedList*)malloc(sizeof(LinkedList));
    if (l == NULL) {
        return NULL;
    }
    l->length = 0;
    l->head = node_new(NULL);  //dummy head;
    return l;
}

Node* node_new(Type e) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->data = e;
    node->next = NULL;
    return node;
}

int linkedlist_insert(LinkedList* l, int index, Type e) {
    if (index < 0 || index > l->length) {
        return 0;
    }
    Node* node = node_new(e);
    if (node == NULL) {
        return 0;
    }
    Node* prev = l->head;
    for (int i = 0; i < index; i++) {
        prev = prev->next;
    }
    node->next = prev->next;
    prev->next = node;
    l->length += 1;
    return 1;
}

int linkedlist_delete(LinkedList* l, int index, Type* e) {
    if (index < 0 || index > l->length - 1) {
        return 0;
    }
    Node* prev = l->head;
    for (int i = 0; i < index; i++) {
        prev = prev->next;
    }
    Node* remove = prev->next;
    *e = remove->data;
    prev->next = remove->next;
    free(remove);
    l->length -= 1;
    return 1;
}

int linkedlist_free(LinkedList* l) {
    Node* node = l->head;
    while (node != NULL) {
        Node* next = node->next;
        free(node);
        node = next;
    }
    free(l);
}

int linkedlist_get(LinkedList* l, int index, Type* e) {
    if (index < 0 || index > l->length - 1) {
        return 0;
    }
    Node* node = l->head->next;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    *e = node->data;
    return 1;
}

int linkedlist_print(LinkedList* l) {
    Node* node = l->head->next;
    while (node != NULL) {
        printf("%d ", *((int*)node->data));
        node = node->next;
    }
    printf("\n");
}

int main() {
    LinkedList* l = linkedlist_new();
    int values1[] = {1, 3, 5, 7, 9};
    for (int i = 0; i < 5; i++) {
        linkedlist_insert(l, i, &values1[i]);
        printf("insert %d \n", values1[i]);
    }
    linkedlist_print(l);
    int values2[] = {2, 4, 6, 8, 10};
    for (int i = 0; i < 5; i++) {
        linkedlist_insert(l, i * 2 + 1, &values2[i]);
        printf("insert %d \n", values2[i]);
    }
    linkedlist_print(l);
    for (int i = 0; i < 5; i++) {
        Type e;
        linkedlist_delete(l, i + 1, &e);
        printf("delete %d \n", *((int*)e));
    }
    linkedlist_print(l);
    for (int i = 0; i < 5; i++) {
        Type e;
        linkedlist_delete(l, 0, &e);
        printf("delete %d \n", *((int*)e));
    }
    linkedlist_print(l);
    return 0;
}
