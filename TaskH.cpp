#include <cmath>
#include <iomanip>
#include <iostream>

inline void Solution(double* array, int& number) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  for (int i = 1; i < number; i++) {
    double tmp_pow1 = pow(*(array + i), 1.0 / (i + 1.0));
    double tmp_pow2 = pow(*(array + i - 1), static_cast<double>(i) / (i + 1.0));
    array[i] = tmp_pow1 * tmp_pow2;
  }
  int questions = 0;
  std::cin >> questions;
  for (int i = 0; i < questions; i++) {
    int left = 0;
    int right = 0;
    double result = 0.0;
    std::cin >> left;
    std::cin >> right;
    left--;
    if (left <= -1) {
      result = *(array + right);
    } else {
      double pow_down = pow(array[left], 1.0 / (right * 1.0 - left));
      double pow_right = pow(array[right], 1.0 / (right * 1.0 - left));
      double pow_left = pow(pow_down, (left + 1.0) / (right + 1.0));
      result = pow_right / pow_left;
      result = pow(result, (right + 1.0));
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(9) << result << "\n";
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int number = 0;
  std::cin >> number;
  double* array = new double[number];
  for (int i = 0; i < number; i++) {
    std::cin >> array[i];
  }
  Solution(array, number);
  delete[] array;
  return 0;
}