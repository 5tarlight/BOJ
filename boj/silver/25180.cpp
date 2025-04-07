#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int nine = n / 9;
    n %= 9;
    if (n == 0) cout << nine;
    else if (nine % 2 == 0) cout << nine + 1;
    else if (n % 2 == 0) cout << nine + 2;
    else cout << nine + 1;
}
