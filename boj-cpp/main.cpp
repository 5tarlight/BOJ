#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int f[n + 1];
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; i++)
        f[i] = f[i - 1] * i;

    int op;
    cin >> op;
    if (op ==  1) {
        int k;
        cin >> k;
        bool used[21];
        fill(used, used + 21, false);
        int idx = n;

        while (k) {
            int num = 1;
            while (used[num]) num++;
            if (k > f[idx]) {
                k -= f[idx];
                do {
                    num++;
                } while (used[num]);
            } else {
                idx--;
                cout << num << ' ';
                used[num] = true;

                if (idx == -1) break;
            }
        }
    }
}
