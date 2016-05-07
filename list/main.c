#include "list.h"
#include "stdio.h"
#include "stdlib.h"

void test(void)
{
    // using to test function
}

static
int create(pList *head, int size)
{
    for(int i = 0; i < size; i++) {
        if(add(head, new())) {
            return i;
        }
    }
    return size;
}


int main(int argc, const char *argv[])
{
    int size = (argc > 1) ? atoi(argv[1]) : 10;
    pList root = NULL;
    create(&root, size);
    printf("origin\n");
    show(root);
    printf("swap head and index 5\n");
    root = swap(&root, get(root, 1), get(root, 5));
    show(root);
    printf("swap tail and index 8\n");
    root = swap(&root, get(root, size), get(root, 8));
    show(root);
    printf("swap head and tail\n");
    root = swap(&root, get(root, size), get(root, 1));
    show(root);
    printf("swap index 3 and 9\n");
    root = swap(&root, get(root, 3), get(root, 9));
    show(root);
    printf("delete index 3\n");
    delete(&root, get(root, 3));
    printf("after delete\n");
    show(root);
    getchar();
#ifdef DEBUG
    test();
#endif
    return 0;
}
