#include <stdio.h>

int main()
{
    double a = 0;
    double *r = &a;
    r+=1;
    printf("%p\n",&a);
    printf("%p\n",&r);
    printf("%p\n",r);
}