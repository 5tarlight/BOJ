#include <iostream>

using namespace std;

int n;
int cnt = 0;
bool col[15];
bool diagonal1[15];
bool diagonal2[15];

// row당 1개씩 배열
void backtrack(int d) {
    if (d == n) {
        cnt++;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (col[i] || diagonal1[i + d] || diagonal2[d - i + n - 1])
            continue;

        col[i] = true;
        diagonal1[i + d] = true;
        diagonal2[d - i + n - 1] = true;

        backtrack(d + 1);

        col[i] = false;
        diagonal1[i + d] = false;
        diagonal2[d - i + n - 1] = false;
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
