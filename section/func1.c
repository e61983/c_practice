#include <stdio.h>
#include "func.h"

static
void func1(char *s) {
    printf("%s:%s -- %s\n", __FILE__, __func__, s);
}

REGISTER_FUNC(func1);
