#include<stdio.h>

int factorial(int x);

int main(){
    int n=0;
    printf("Enter your number : ");
    scanf("%d", &n);
    printf("%d! = %d", n, factorial(n));
}

int factorial(int x){
    int fact = 1;
    if(x < 1){
        return fact;
    }
    else{
        while(x>1){
            fact *= x;
            x--;
        }
    }
    return fact;
}