#ifndef __LIST__H_
#define __LIST__H_

typedef struct List {
    int value;
    struct List* next;
} List, *pList;

pList new();
int add(pList *head, pList node);
int delete(pList *head, pList node);
pList swap(pList *head, pList node1, pList node2);
void show(pList head);
pList get(pList head, int index);
#endif
