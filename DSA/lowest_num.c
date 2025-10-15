#include <stdio.h>

void find_lowest_number(int arr[], int size) {
    if (size <= 0) {
        printf("Array is empty.\n");
        return;
    }
    int lowest = arr[0];
    for (int i =1; i < size; i++) {
        if (arr[i] < lowest) {
            lowest = arr[i];
        }
    }
    printf("The lowest number in the array is: %d\n", lowest);
}

int main() {
    int numbers[] = {34, -2, 45, 0, 23, -10, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    find_lowest_number(numbers, size);
    return 0;
}