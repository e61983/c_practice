#include <stdio.h>
#include "func.h"

extern void *__start_my_func;
extern void *__stop_my_func;

int main(int argc, char *argv[])
{
    printf("start: %p\n", &__start_my_func);
    printf("stop: %p\n", &__stop_my_func);

    struct func_package *fp = (void*)&__start_my_func;
    printf("name: %s\n", fp->name);
    fp->func("1");
    fp++;
    printf("name: %s\n", fp->name);
    fp->func("2");
    return 0;
}
