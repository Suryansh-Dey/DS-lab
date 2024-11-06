#include <stdio.h>
int main()
{
    int *p = malloc(sizeof(int));
    *p = 5;
    printf("%ld", *p);
    return 0;
}