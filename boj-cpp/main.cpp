#include <iostream>

using namespace std;

int n;
int cnt = 0;
bool col[20];
bool diag1[40];
bool diag2[40];

void backtrack(int d) {
    if (d == n) {
        cnt++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (col[i] || diag1[d + i] || diag2[d - i + n - 1])
            continue;

        col[i] = true;
        diag1[d + i] = true;
        diag2[d - i + n - 1] = true;

        backtrack(d + 1);

        col[i] = false;
        diag1[d + i] = false;
        diag2[d - i + n - 1] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    backtrack(0);

    cout << cnt;
}
