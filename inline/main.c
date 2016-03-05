#include <stdio.h>

#ifdef USE
extern inline int foo(int a, int b);
inline int foo(int a,int b)
{
    return a < b ;
}
#else
int foo(int a, int b);
int foo(int a,int b)
{
    return a<b;
}
#endif

int main(int argc, const char *argv[])
{
    printf("%d\n",foo(1,2));
    printf("%d\n",foo(2,1));
}
