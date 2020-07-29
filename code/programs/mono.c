#include <stdio.h>

int main() {
    int x, fat;
    r1: printf("monolitico\n");
    r2: x = 10;
    r3: fat = 1;
    r4: fat = fat * x;
    r5: x = x - 1;
    r6: if (x > 1) goto r4; else goto r7;
    r7: printf("fat=%d\n", fat);
    r8: return 0;
}