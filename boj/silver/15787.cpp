#include <iostream>
#include <algorithm>

using namespace std;

bool visited[1 << 20];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int a[n];
    fill(a, a + n, 0);

    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int i, x;
            cin >> i >> x;
            a[i - 1] |= 1 << (x - 1);
        } else if (op == 2) {
            int i, x;
            cin >> i >> x;
            a[i - 1] &= ~(1 << (x - 1));
        } else if (op == 3) {
            int i;
            cin >> i;
            a[i - 1] <<= 1;
            a[i - 1] &= 0b11111111111111111111;
        } else {
            int i;
            cin >> i;
            a[i - 1] >>= 1;
        }
    }

    int ans = 0;
    for (int v : a) {
        if (!visited[v]) {
            visited[v] = true;
            ans++;
        }
    }

    cout << ans;
}
