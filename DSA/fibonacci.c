#include <stdio.h>

void fibonacci_loop(int count) {
    double prev = 0, curr = 1;
    printf("%.0f %.0f ", prev, curr);

    for (int i = 2; i < count; i++) {
        double next = prev + curr;
        printf("%.0f ", next);
        prev = curr;
        curr = next;
    }
    printf("\n");
}

int fibonacci_recursive(int n) {
    if (n <= 1) return n;
    return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

int main() {
    fibonacci_loop(10);
    printf("fibonacci at position 10: %d\n", fibonacci_recursive(10));
    return 0;
}