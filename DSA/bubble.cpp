#include <iostream>

using namespace std;

void bubble_sort(int arr[], int size){
    for (int n = 0; n < size - 1; n++){
        bool swapped = false;
        for (int i = 0; i < size - n - 1; i++){
            if (arr[i] > arr[i+1]){
                int tmp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = tmp;
                swapped = true;
            }
        }
        if (!swapped) {
            cout << "Array is already sorted. Exiting early at pass " << n + 1 << "." << endl;
            break;
        }
    }
}

int main(){
    int array[] = {9, 3, 6, 10, 1, 0, 2, 8, 4, 7, 5};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Original Array: ";
    for (int x : array) cout << x << " ";
    cout << endl;

    bubble_sort(array, size);

    cout << "Sorted Array: ";
    for (int x : array) cout << x << " ";
    cout << endl;

    return 0;
}
