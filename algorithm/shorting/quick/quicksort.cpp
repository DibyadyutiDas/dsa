#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

template <size_t N>
void quicksort(array<int, N>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (arr[j] < pivot) {
                ++i;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    array<int, 6> arr = {10, 7, 8, 9, 1, 5};
    quicksort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}