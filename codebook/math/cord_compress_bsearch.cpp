#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
        b.push_back(x);
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    vector<int> ans;
    for (int v : b) {
        int idx = lower_bound(a.begin(), a.end(), v) - a.begin();
        ans.push_back(idx);
    }

    for (int v : ans)
        cout << v << ' ';
}
