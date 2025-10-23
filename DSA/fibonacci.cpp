#include <iostream>

using namespace std;

void fibonacci_loop(int count) {
    double prev = 0, curr = 1;
    cout << prev << " " << curr << " ";

    for (int i = 2; i < count; i++) {
        double next = prev + curr;
        cout << next << " ";
        prev = curr;
        curr = next;
    }
    cout << endl;
}

int fibonacci_recursive(int n) {
    if (n <= 1) return n;
    return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

int main() {
    fibonacci_loop(10);
    cout << "fibonacci at position 10: " << fibonacci_recursive(10) << endl;
    return 0;
}
