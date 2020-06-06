#include "bintree.h"

#include <stdio.h>
#include <stdlib.h>

Tree* tree_new() {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    if (tree == NULL) {
        return NULL;
    }
    tree->root = NULL;
    return tree;
}

Node* node_new(Type e) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->data = e;
    node->left = node->right = NULL;
    return node;
}

int tree_pre_order_traversal(Node* node) {
    if (node == NULL) {
        return 0;
    }
    printf("%d ", node->data);
    tree_pre_order_traversal(node->left);
    tree_pre_order_traversal(node->right);
}

int tree_in_order_traversal(Node* node) {
    if (node == NULL) {
        return 0;
    }
    tree_in_order_traversal(node->left);
    printf("%d ", node->data);
    tree_in_order_traversal(node->right);
}

int tree_post_order_traversal(Node* node) {
    if (node == NULL) {
        return 0;
    }
    tree_post_order_traversal(node->left);
    tree_post_order_traversal(node->right);
    printf("%d ", node->data);
}

int tree_level_order_traversal(Node* node) {
    int level = 1;
    while (tree_print_level(node, level)) {
        level++;
        printf("\n");
    }
}

int tree_print_level(Node* node, int level) {
    if (node == NULL) {
        return 0;
    }
    if (level == 1) {
        printf("%d ", node->data);
        return 1;
    }
    int left = tree_print_level(node->left, level - 1);
    int right = tree_print_level(node->right, level - 1);
    return left || right;
}

int main() {
    Tree* tree = tree_new();
    tree->root = node_new(0);
    Node* root = tree->root;
    root->left = node_new(1);
    root->right = node_new(2);
    root->left->left = node_new(3);
    root->left->right = node_new(4);
    root->right->left = node_new(5);
    root->right->right = node_new(6);
    tree_level_order_traversal(tree->root);
    printf("\n");
    tree_pre_order_traversal(tree->root);
    printf("\n");
    tree_in_order_traversal(tree->root);
    printf("\n");
    tree_post_order_traversal(tree->root);
    return 0;
}
