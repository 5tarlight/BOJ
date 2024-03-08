#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int small[n], big[n];
    int maxq[n], minq[n];

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        big[i] = maxq[i] = a + b;
        small[i] = minq[i] = a - b;
    }

    sort(maxq, maxq + n);
    sort(minq, minq + n);

    for (int i = 0; i < n; i++) {
        int s = lower_bound(maxq, maxq + n, small[i]) - maxq + 1;
        int e = upper_bound(minq, minq + n, big[i]) - minq;

        cout << s << ' ' << e << '\n';
    }
}
