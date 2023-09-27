#include <iostream>

using namespace std;

int n, m;
int num[10];
bool used[10];

void backtrack(int d) {
    if (d == m) {
        for (int i = 0; i < m; i++)
            cout << num[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            num[d] = i;
            used[i] = true;

            backtrack(d + 1);

            used[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    backtrack(0);
}
