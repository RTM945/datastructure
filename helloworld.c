#include <stdio.h>
#include <stdlib.h>
int main() {
    int* a = (int*)malloc(sizeof(int) * 2);
    a[0] = 1;
    a[1] = 2;
    printf("%s \n", &a[1] == a + 1 ? "true" : "false");
    return 0;
}