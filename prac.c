#include <stdio.h>

int* num;

int main(void) {
    *num = 1;
    printf("%d\n", *num);

    return 0;
}