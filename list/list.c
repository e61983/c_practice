#include "list.h"
#include "stdlib.h"
#include "stdio.h"

static void in_swap(pList node1, pList node2) ;
pList new() {
    pList node = NULL;
    
    if (NULL == (node = malloc(sizeof(struct List))))
        return NULL;
        
    node->value = 0;
    node->next = NULL;
    return node;
}

int add(pList head, pList node) {
    if(!(node && head)) return 1;
    
    node->next = head->next;
    head->next = node;
    return 0;
}

int show(pList head) {
    unsigned int lenth = 0;
    
    for(pList node = head; node != NULL;
            node = node->next, lenth++) {
        printf("%d -> ", node->value);
    }
    
    printf("\n");
    return lenth;
}

pList swap(pList head, pList node1, pList node2) {
    if(!(head && node1 && node2)) return head;
    
    if(node1 == node2)return head;
    
    pList pre_node1 = NULL;
    pList pre_node2 = NULL;
    
    for(pList node = head; node != NULL && !(pre_node1
            && pre_node2) ; node = node->next) {
        if(node1 == node->next) pre_node1 = node;
        
        if(node2 == node->next) pre_node2 = node;
    }
    
    if(head == node1 && pre_node2 ) {
        pre_node2->next = node1;
        in_swap(node1, node2);
        return node2;
    }
    
    if(head == node2 && pre_node1) {
        pre_node1->next = node2;
        in_swap(node1, node2);
        return node1;
    }
    
    if(!(pre_node1 && pre_node2))return head;
    
    pre_node1->next = node2;
    pre_node2->next = node1;
    in_swap(node1, node2);

    return head;
}

static void in_swap(pList node1, pList node2) {
    pList tmp = node1->next;
    node1->next = node2->next;
    node2->next = tmp;
}

