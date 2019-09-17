#include <stdio.h>
#include <stdint.h>
#include "func.h"

int main(int argc, char *argv[])
{
    struct func_package *fp = get_first_package();
    foreach_func(fp) {
        printf("name: %s\n", i->name);
        i->func("1");
    }
    return 0;
}
