#include <iostream>
#include <string>

void BubbleSort(int* arr, std::string& arr2, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                std::swap(arr2[j], arr2[j + 1]);
            }

        }
    }
}

int main() {
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    std::string words;
    int* arr = new int[n];
    int* arr_copy = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::cin >> words;

    std::copy(arr, arr + n, arr_copy);

    for (int id = 0; id < k; id++) {
        BubbleSort(arr, words, n);
        std::copy(arr_copy, arr_copy + n, arr);
    }

    std::cout << words;
    delete[] arr;
    delete[] arr_copy;
}