#include "bits/stdc++.h"

using namespace std;

struct W {
    int p, i;
    bool operator<(const W& other) const {
        return p > other.p;
    }
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    vector<W> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].p;
        a[i].i = i + 1;
    }

    sort(a.begin(), a.end());

    vector<int> ans;

    for (int i = 0; i < k; i++)
        ans.push_back(a[i].i);

    int l = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].p == a[l].p)
            l++;
        else
            break;
    }

    int idx = l;
    for (int i = 0; i < m - k; i++) {
        ans.push_back(a[idx].i);

        idx--;
        if (idx < 0)
            idx = l;
    }

    for (int v : ans) {
        cout << v << " ";
    }
}