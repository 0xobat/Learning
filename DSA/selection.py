def selection_sort(arr):
    """
    Sorts an array using the selection sort algorithm.
    """
    n = len(arr)

    for i in range(n - 1):
        min_index = i

        # Find the minimum element in the unsorted portion
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j

        # Swap the found minimum element with the first element
        arr[i], arr[min_index] = arr[min_index], arr[i]

    return arr


if __name__ == "__main__":
    my_array = [64, 34, 25, 5, 22, 11, 90, 12]

    print("Original array:", my_array)
    selection_sort(my_array)
    print("Sorted array:", my_array)
