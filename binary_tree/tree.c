#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

static int
show(pNode root);

static pNode
find(int data, pNode root);

void
unit_test();

int main(int argc, const char *argv[])
{
    pNode node_3 = new(3);
    pNode node_4 = new(4);
    pNode node_7 = new(7);
    pNode node_19 = new(19);
    pNode node_25 = new(25);
    pNode node_54 = new(54);
    pNode node_52 = new(52);
    pNode node_8 = new(8);
    pNode node_15 = new(15);
    add(node_3, node_19);
    add(node_25, node_19);
    add(node_7, node_19);
    add(node_54, node_19);
    add(node_4, node_19);
    add(node_52, node_19);
    add(node_8, node_19);
    add(node_15, node_19);
    show(node_19);
    pNode node_find=NULL;
    if(NULL != (node_find= find(52,node_19))){
        printf("Find %d at %p\n",node_find->data,node_find );
    }
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

static int
show(pNode root)
{
    static int count = 1;
    int current_count = count;
    char showDot[current_count+1];
    memset(showDot,'.',current_count);
    showDot[0]='|';
    showDot[current_count]='\0';
    printf("%d\n",root->data);
    count++;
    if(NULL != root->left) {
        printf("%sL",showDot);
        show(root->left);
    }
    if(NULL != root->right) {
        printf("%sR",showDot);
        show(root->right);
    }
    return count--;
}
static pNode
find(int data, pNode root)
{
    if(NULL == root) return NULL;
    for(pNode current = root;
            current!=NULL;
            current = data > current->data? current->right:current->left) {
        if(data==current->data)return current;

    }
    return NULL;

}

void
unit_test()
{
}
