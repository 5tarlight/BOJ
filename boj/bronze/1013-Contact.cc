#include <iostream>
#include <regex>
#include <string>

void solve(void) {
  std::string input;
  std::cin >> input;

  std::regex pattern("(100+1+|01)+");
  std::cout << (std::regex_match(input, pattern) ? "YES" : "NO") << std::endl;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int test_case;
  std::cin >> test_case;
  for (int t = 0; t < test_case; t++)
    solve();
}
