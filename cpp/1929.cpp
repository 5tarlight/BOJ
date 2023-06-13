#include <ios>
#include <iostream>
#include <stdio.h>
using namespace std;

bool is_prime(int num) {
  for (int i = 2; i <= num / 2; i++)
    if (num % i == 0)
      return false;

  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  scanf("%d %d", &n, &m);

  for (int i = n; n <= m; i++)
    if (is_prime(i))
      cout << i << endl;
}
