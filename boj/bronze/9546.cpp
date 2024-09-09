#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n = 0;

        for (int i = 0; i < k; i++)
            n = 2 * n + 1;

        cout << n << '\n';
    }
}
