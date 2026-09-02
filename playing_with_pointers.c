#include<stdio.h>

int main(){
    // * -> Value at
    // & -> Address of
    int a = 25;
    int *p = &a;
    int **pp = &p;
    printf("%d, %d\n", *p, **pp);
    (*p)--;
    printf("%d, %d\n", *p, a);
    a+=10;
    printf("%d\n", *p);
    int x = 44;
    *pp = &x;
    (**pp)-=4;
    printf("%d, %d, %d", **pp, *p, a);
}