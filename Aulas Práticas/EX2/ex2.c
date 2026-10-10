//implementaçao de funçoes
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include 'ex2.h'

void func(int n){
    printf("%d ", n);
        if (n > 0){
            func(n - 1);
            printf("* ");
        }
}