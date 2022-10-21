#include <iostream>

bool BinarySearch(const int* begin, const int* end, int target) {
    int left = 0;
    int right = end - begin;
    while (right > left + 1) {
        int mid = (left + right) / 2;
        if (*(begin + mid) <= target) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    return (target == *(begin + left));
}

int main() {
    int number;
    std::cin >> number;
    int* array = new int[number];
    for (int i = 0; i < number; i++) {
        std::cin >> array[i];
    }
    int questions;
    std::cin >> questions;
    for (int i = 0; i < questions; i++) {
        int left = 0;
        int right = 0;
        int asked = 0;
        std::cin >> left;
        std::cin >> right;
        std::cin >> asked;
        int* ptr = array;
        bool result = BinarySearch(ptr + left, ptr + right, asked);
        if (result) {
            std::cout << "YES\n";
        }
        else {
            std::cout << "NO\n";
        }
    }
    delete[] array;
    return 0;
}