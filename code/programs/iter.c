#include <stdio.h>

int main() {
    int x, fat;
    printf("iterativo\n");
    x = 5;
    fat = 1;
    while (x > 1) {
      fat = fat * x;
      x = x - 1;
    }
    printf("fat=%d\n", fat);

    return 0;
}