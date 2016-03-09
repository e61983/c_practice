#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

typedef struct Node {
    Node *left;
    Node *right;
    int data;
} Node, *pNode;

static pNode
new(int data);

static int
add(pNode node, pNode root);

void
unit_test();

int main(int argc, const char *argv[])
{
    pNode test = new(3);
    pNode test2 = new(4);
    add(test, test2);
#ifdef DEBUG
    unit_test();
#endif
    return 0;
}
static pNode
new(int data)
{
    pNode node = NULL;
    if(NULL==(node = malloc(sizeof(Node)))) return NULL;
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    return node;
}

static int
add(pNode node, pNode root)
{
    if( root == node)
        return 0;
    if(root->data <= node->data) {
        if(NULL == root->right) {
            root->right = node;
        } else {
            add(node,root->right);
        }
        return 1;
    }
    if(root->data > node->data) {
        if(NULL == root->left) {
            root->left = node;
        } else {
            add(node,root->left);
        }
        return 2;
    }
    return 3;
}

void
unit_test()
{
}


