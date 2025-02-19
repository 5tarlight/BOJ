#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), greater<>());

    for (int i = 0; i < n - 2; i++) {
        if (a[i] < a[i + 1] + a[i + 2]) {
            cout << a[i] + a[i + 1] + a[i + 2];
            return 0;
        }
    }

    cout << -1;
}
