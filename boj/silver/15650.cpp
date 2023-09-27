#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;

bool visited[8];
int num[8];
void backtrack(int x, int d) {
    if (d == m) {
        for (int i = 0; i < m; i++) {
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = d == 0 ? 0 : num[d - 1]; i < n; i++) {
        if (visited[i])
            continue;

        num[d] = i + 1;
        visited[i] = true;
        backtrack(x, d + 1);
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    backtrack(0, 0);
}
