#include "bits/stdc++.h"

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    if (x + 1 == y) {
      cout << "YES\n";
    } else {
      int tmp = x - y + 1;
      if (tmp > 0 && tmp % 9 == 0)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
}
