#include <iostream>

using namespace std;

void find_lowest_number(int arr[], int size) {
    if (size <= 0) {
        cout << "Array is empty." << endl;
        return;
    }
    int lowest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < lowest) {
            lowest = arr[i];
        }
    }
    cout << "The lowest number in the array is: " << lowest << endl;
}

int main() {
    int numbers[] = {34, -2, 45, 0, 23, -10, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    find_lowest_number(numbers, size);
    return 0;
}
