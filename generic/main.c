#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define format(x) _Generic((x), \
    char: "%c\n", \
    char*:"%s\n", \
    int:"%d\n", \
    default: "error \n" \
    )

#define print(x) printf(format((x)),(x))

#define format2(x,y) _Generic((x), \
    char: _Generic((y), \
        char:"%c - %c\n", \
        char*:"%c - %s\n", \
        int:"%c - %d\n", \
        default:"error\n" \
        ), \
    char*: _Generic((y), \
        char:"%s - %c\n", \
        char*:"%s - %s\n", \
        int:"%s - %d\n", \
        default:"error\n" \
        ), \
    int: _Generic((y), \
        char:"%d - %c\n", \
        char*:"%d - %s\n", \
        int:"%d - %d\n", \
        default:"error\n" \
        ), \
    default:"error\n" \
  )

#define print2(x, y) printf(format2(x,y),x,y)

int main(int argc, char **argv)
{
    char test_char = 'c';
    char *test_str = "Hello word";
    int test_int = 3;

    printf("test 1 parameter\n");
    print(test_char);
    print(test_int);
    print(test_str);

    printf("\n");

    printf("test 2 parameters\n");
    print2(test_int,test_char);

    return 0;
}
