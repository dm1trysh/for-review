#include <iostream>

int main() {
  int number = 0;
  std::cin >> number;
  int* array = new int[number];
  for (int i = 0; i < number; i++) {
    std::cin >> array[i];
  }
  int left = -1;
  int right = number - 1;
  const int kLastEl = *(array + number - 1);
  while (right > left + 1) {
    int mid = (left + right) / 2;
    if (*(array + mid) > kLastEl) {
      left = mid;
    } else {
      right = mid;
    }
  }
  std::cout << right;
  delete[] array;
  return 0;
}