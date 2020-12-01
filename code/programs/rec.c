#include <stdio.h>

int fatorial(int x) {
  if (x == 1) return 1;
  return x*fatorial(x-1);
}

int main() {
    printf("recursivo\n");
    printf("fat=%d\n", fatorial(5));
    return 0;
}

//fatorial(10){10*fatorial(9){9*fatorial(8)}}