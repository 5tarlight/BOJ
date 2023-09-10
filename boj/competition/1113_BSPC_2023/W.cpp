#include <iostream>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int j, n;
  cin >> j >> n;
  int scores[n];
  cin.ignore();

  for (int i = 0; i < n; i++) {
    string line;
    int score = 0;
    getline(cin, line);

    for (char c : line) {
      if ('A' <= c && c <= 'Z')
        score += 4;
      else if ('a' <= c && c <= 'z' || '0' <= c && c <= '9')
        score += 2;
      else
        score += 1;
    }

    scores[i] = score;
  }

  int count = 0;
  for (int s : scores) {
    if (s <= j)
      count++;
  }

  cout << count;
}
