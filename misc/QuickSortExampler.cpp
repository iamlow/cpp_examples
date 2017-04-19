#include <iostream>
#include <algorithm>    // std::swap

void quick_sort(int *nums, int left, int right)
{
  int i = left, j = right;
  // int p = nums[(left + right) / 2];
  // std::cout << p << "=>" << p << std::endl;
  int p = nums[left];

  do {
    while (p > nums[i]) i++;
    while (p < nums[j]) j--;
    if (i <= j) {
      std::swap(nums[i], nums[j]);
      i++;
      j--;
    }
  } while (i <= j);

  if (left < j) quick_sort(nums, left, j);
  if (i < right) quick_sort(nums, i, right);
}

void quicksort(int *nums, const int size)
{
  quick_sort(nums, 0, size - 1);
}

int main(void)
{
  int nums[8] = { 5, 1, 2, 3, 4, 4, 3, 0 };
  quicksort(nums, 8);
  for (auto elem : nums) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
  return 0;
}
