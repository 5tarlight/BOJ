#include <iostream>

using namespace std;

int n, m;
int nums[10];

void backtrack(int d) {
    if (d == m) {
        for (int i = 0; i < m; i++) {
            cout << nums[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        nums[d] = i;

        if (d > 0 && nums[d - 1] > i)
            continue;

        backtrack(d + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    backtrack(0);
}
