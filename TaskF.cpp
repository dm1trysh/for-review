#include <iostream>
#include <vector>
const uint64_t kMod = (static_cast<uint64_t>(1) << 9) - 1;

inline void RadixSort(std::vector<uint64_t>& arr, int number) {
  int n = arr.size();
  const uint64_t kDiv = static_cast<uint64_t>(1) << ((number - 1) * 8);
  std::vector<uint64_t> cnt(kMod + 1, 0);
  std::vector<uint64_t> arr_copy(n, 0);
  for (int i = 0; i < n; i++) {
    uint64_t key = arr[i] & (kMod << (number - 1) * 8);
    key /= kDiv;
    cnt[key]++;
    arr_copy[i] = arr[i];
  }
  std::vector<uint64_t> pref(kMod + 1, 0);
  pref[0] = 0;
  for (size_t i = 1; i < pref.size(); i++) {
    pref[i] = pref[i - 1] + cnt[i - 1];
  }
  for (int i = 0; i < n; i++) {
    uint64_t key = arr_copy[i] & (kMod << (number - 1) * 8);
    key /= kDiv;
    arr[pref[key]++] = arr_copy[i];
  }
}

inline void LSD(std::vector<uint64_t>& arr) {
  for (int i = 1; i <= 8; i++) {
    RadixSort(arr, i);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int n;
  std::cin >> n;
  std::vector<uint64_t> arr(n);
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  LSD(arr);
  for (auto el : arr) {
    std::cout << el << "\n";
  }
  return 0;
}