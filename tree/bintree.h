typedef int Type;

typedef struct _Node {
    Type data;
    struct _Node* left;
    struct _Node* right;
} Node;

typedef struct _Tree {
    Node* root;
} Tree;

// Tree* tree_new(Type* datas);

// Node* node_new(Type e, Node* parent, int left);

Tree* tree_new();

Node* node_new(Type e);

int tree_pre_order_traversal(Node* node);

int tree_in_order_traversal(Node* node);

int tree_post_order_traversal(Node* node);

int tree_level_order_traversal(Node* node);

int tree_print_level(Node* node, int level);