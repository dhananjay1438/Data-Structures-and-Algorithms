#include <iostream>
#include <vector>

void is_positive(std::string input, std::vector<std::string> &arr) {

  for (auto &str : arr) {

    int count = 0;
    std::string temp = input;
    for (size_t j = 0; j < str.length(); j++) {
      size_t index = temp.find(str[j]);
      if (index != std::string::npos) {
        temp.erase(temp.begin() + 0, temp.begin() + index);
        count++;
      } else {
        std::cout << "NEGATIVE\n";
        break;
      }
      if (count == static_cast<int>(str.length())) {
        std::cout << "POSITIVE\n";
      }
    }
  }
}
int main(void) {
  std::string input;
  int n;

  std::cin >> input;
  std::cin >> n;

  std::vector<std::string> vec(n);

  for (int i = 0; i < n; i++) {
    std::cin >> vec[i];
  }
  is_positive(input, vec);
  return 0;
}
