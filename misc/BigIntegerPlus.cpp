#include <iostream>
#include <cstdint>
#include <climits>
#include <vector>
#include <algorithm>
int main(int argc, char *argv[])
{
  // uint16_t input_num = USHRT_MAX - 1;
  // uint8_t nums[2] = { 0, };
  //
  // uint8_t a = 1;
  // printf("%d %d %d %d %d\n", a<<8, a<<2, a<<3, a<<4, a<<5);
  // nums[0] = input_num;
  // nums[1] = input_num >> 8;
  //
  // for (uint8_t item : nums) {
  //     printf("%d\n", item);
  //     // std::cout << std::dec << item << std::endl;
  // }
  //
  // uint64_t input_num64 = UINT64_MAX - 1;
  // uint32_t nums_32[2] = { 0, };
  //
  // nums_32[0] = input_num64;
  // nums_32[1] = input_num64 >> 32;
  //
  // for (uint32_t item : nums_32) {
  //     printf("%u\n", item);
  //     // std::cout << std::dec << item << std::endl;
  // }s

  if (3 != argc) {
    std::cout << "invalid arguement! ex) $ ./bigintegerplus 123 45678\n";
    return -1;
  }

  std::vector<std::string> nums;
  nums.push_back(argv[1]);
  nums.push_back(argv[2]);

  for (auto & item : nums) {
    std::reverse(item.begin(), item.end());
  }

  // for (auto i = nums[0].rbegin(); i != nums[0].rend(); ++i) {
  //     std::cout << ch << std::endl;
  // }
  // for (const auto ch : nums[0]) {
  //     std::cout << ch << std::endl;
  // }
  // for (const auto ch : nums[1]) {
  //     std::cout << ch << std::endl;
  // }

  std::string *min_num = nullptr;
  int min_len = 0;

  std::string *max_num = nullptr;
  int max_len = 0;

  if (nums[0].length() < nums[1].length()) {
    min_num = &nums[0];
    min_len = nums[0].length();
    max_num = &nums[1];
    max_len = nums[1].length();
  } else {
    min_num = &nums[1];
    min_len = nums[1].length();
    max_num = &nums[0];
    max_len = nums[0].length();
  }

  std::string sum;
  int up = 0;

  for (int i = 0; i < min_len; i++) {
    sum += std::to_string(((min_num->at(i) - '0') + (max_num->at(i) - '0') + up) % 10);
    up = ((min_num->at(i) - '0') + (max_num->at(i) - '0') + up) / 10;
  }

  for (int i = min_len; i < max_len; i++) {
    sum += std::to_string(((max_num->at(i) - '0') + up) % 10);
    up = ((max_num->at(i) - '0') + up) / 10;
  }

  if (up)
    sum += std::to_string(up);

  std::reverse(sum.begin(), sum.end());
  std::cout << sum << std::endl;

  return 0;
}
