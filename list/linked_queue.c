#include "linked_queue.h"

#include <stdio.h>
#include <stdlib.h>

LinkedQueue* queue_new() {
    LinkedQueue* q = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    if (q == NULL) {
        return NULL;
    }
    q->length = 0;
    q->head = q->tail = NULL;
    return q;
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

int queue_offer(LinkedQueue* q, Type e) {
    Node* node = node_new(e);
    if (node == NULL) {
        return 0;
    }
    if (q->length == 0) {
        q->head = node;
    } else {
        q->tail->next = node;
    }
    q->tail = node;
    q->length += 1;
    return 1;
}

int queue_poll(LinkedQueue* q, Type* e) {
    if (q->length == 0) {
        *e = NULL;
        return 1;
    }
    Node* node = q->head;
    q->head = node->next;
    if (q->head == NULL) {
        q->tail == NULL;
    }
    q->length -= 1;
    *e = node->data;
    free(node);
    return 1;
}

int queue_print(LinkedQueue* q) {
    Node* node = q->head;
    while (node != NULL) {
        printf("%d ", *(int*)node->data);
        node = node->next;
    }
    printf("\n");
    return 1;
}

int main() {
    LinkedQueue* q = queue_new();
    int arr[] = {0, 1, 2, 3, 4};
    for (int i = 0; i < 5; i++) {
        queue_offer(q, &arr[i]);
        printf("offer %d\n", arr[i]);
        queue_print(q);
    }
    for (int i = 0; i < 5; i++) {
        Type e;
        queue_poll(q, &e);
        printf("poll %d\n", *(int*)e);
        queue_print(q);
    }
    queue_print(q);
}