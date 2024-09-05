#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int m = 1;; m++) {
            set<int> used;
            for (int v : a)
                used.insert(v % m);

            if (used.size() == n) {
                cout << m << '\n';
                break;
            }
        }
    }
}
