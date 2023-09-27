#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;

int num[8];
void backtrack(int x, int d) {
    if (d == m) {
        for (int i = 0; i < m; i++) {
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        num[d] = i + 1;
        backtrack(x, d + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    backtrack(0, 0);
}
