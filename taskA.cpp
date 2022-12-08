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
  size_t number;
  std::cin >> number;
  int* array = new int[number];
  for (size_t i = 0; i < number; i++) {
    std::cin >> array[i];
  }
  size_t questions;
  std::cin >> questions;
  for (size_t i = 0; i < questions; i++) {
    int left = 0, right = 0, asked = 0;
    std::cin >> left >> right >> asked;
    int* ptr = array;
    bool result = BinarySearch(ptr + left, ptr + right, asked);
    std::cout << result ? "YES\n" : "NO\n";
  }
  delete[] array;
  return 0;
}