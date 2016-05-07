#include "list.h"
#include "stdlib.h"
#include "stdio.h"

pList new()
{
    static int member = 0;
    pList node = NULL;
    if (NULL == (node = malloc(sizeof(struct List)))) {
        return NULL;
    }
    node->value = member++;
    node->next = NULL;
    return node;
}

int add(pList *head, pList node)
{
    if(*head == node) {
        return 1;
    }
    pList *current = head;
    while(*current != NULL) {
        current = &(*current)->next;
    }
    *current = node;
    return 0;
}

int delete(pList *head, pList node)
{
    pList *current = head;
    while(*current != node) {
        current = &(*current)->next;
    }
    *current = node->next;
    return 0;
}

void show(pList head)
{
    for(int i = 1; head != NULL; i++) {
        printf("index : %02d\t%02d(%p)->(%p)\r\n", i, head->value, head, head->next);
        head = head->next;
    }
}

pList swap(pList *head, pList node1, pList node2)
{
    pList tmp = NULL;
    pList *current = head;
    pList *pre_node1 = NULL;
    pList *pre_node2 = NULL;
    if(node1 == NULL || node2 == NULL) {
        return *head;
    }
    if(node1 == node2) {
        return *head;
    }
    while(*current != NULL && (pre_node1 == NULL || pre_node2 == NULL)) {
        if(*current == node1) {
            pre_node1 = current;
        }
        if(*current == node2) {
            pre_node2 = current;
        }
        current = &(*current)->next;
    }
    tmp = (*pre_node1)->next;
    (*pre_node1)->next = (*pre_node2)->next;
    (*pre_node2)->next = tmp;
    tmp = *pre_node1;
    *pre_node1 = *pre_node2;
    *pre_node2 = tmp;
    return *head;
}

pList get(pList head, int index)
{
    pList tmp = head;
    for(int i = 0; (i < index - 1) && (tmp) != NULL; i++) {
        tmp = tmp->next;
    }
    return tmp;
}

