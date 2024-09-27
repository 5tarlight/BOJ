#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, l;
    cin >> n >> l;
    vector<pair<int, pair<int, int>>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second.first >> a[i].second.second;

    int pos = 0;
    int time = 0;
    for (auto [nxt, p] : a) {
        auto [r, g] = p;

        time += nxt - pos;
        pos = nxt;

        if (time % (r + g) < r)
            time += r - time % (r + g);
    }

    cout << time + l - pos;
}
