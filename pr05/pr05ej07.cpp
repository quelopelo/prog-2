#include <stdio.h>

typedef unsigned int uint;

uint fibonacci(uint n);

int main() {
    uint n;
    printf("Ingrese un número natural: ");
    scanf("%d", &n);
    printf("Fibonacci(%d): %d\n", n, fibonacci(n));
    return 0;
}

uint fibonacci(uint n) {
    if (n <= 1)
        return 1;
    else {
        uint ant1 = 1;
        uint ant2 = 1;
        uint res = 2;
        for (uint i = 3; i <= n; ++i) {
            ant2 = ant1;
            ant1 = res;
            res = ant1 + ant2;            
        }
        return res;
    }
}
