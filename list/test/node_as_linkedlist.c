#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node* next;
} Node;

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    if (head == NULL) {
        return 0;
    }
    head->next = NULL;
    head->data = 0;
    Node* move = head;
    for (int i = 1; i < 5; i++) {
        Node* node = (Node*)malloc(sizeof(Node));
        if (node == NULL) {
            return 0;
        }
        node->data = i;
        node->next = NULL;
        move->next = node;
        move = move->next;
    }
    printf("%s \n", head == move ? "true" : "false");
    Node* node = head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");

    // int a = 2;
    // int* b = &a;
    // *b = 1;
    // printf("%d\n", a); // why 1 ?
    return 0;
}