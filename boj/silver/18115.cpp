#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    deque<int> d;
    int a[n];
    for (int i = n - 1; i >= 0; i--)
        cin >> a[i];

    for (int i = 1; i <= n; i++) {
        int x = a[i - 1];

        if (x == 1) {
            d.push_front(i);
        } else if (x == 2) {
            int t = d.front();
            d.pop_front();
            d.push_front(i);
            d.push_front(t);
        } else if (x == 3) {
            d.push_back(i);
        }
    }

    for (int v : d)
        cout << v << ' ';
}
