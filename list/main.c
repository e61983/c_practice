#include "list.h"
#include "stdlib.h"

void test(void) {
    // using to test function
}

int main(int argc, const char *argv[]) {
    pList test1 = new();
    pList test2 = new();
    pList test3 = new();
    pList test4 = new();
    pList head = test1;
    test1->value = 1;
    test2->value = 2;
    test3->value = 3;
    test4->value = 4;
    add(head, test2);
    add(head, test3);
    add(head, test4);
    show(head);
    head = swap(head, test2, test4);
    show(head);
    head = swap(head, test1, test4);
    show(head);
    head = swap(head, test4, test1);
    show(head);
    head = swap(head, test4, test4);
    show(head);
    head = swap(head, test1, test2);
    show(head);
#ifdef DEBUG
    test();
#endif
    return 0;
}
