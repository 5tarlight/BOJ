#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    long long a[n];
    fill(a, a + n, 0);

    while (q--) {
        int op, p, x;
        cin >> op >> p >> x;

        if (op == 1)
            a[p - 1] += x;
        else {
            long long sum = 0;
            for (int i = p - 1; i < x; i++)
                sum += a[i];
            cout << sum << '\n';
        }
    }
}
