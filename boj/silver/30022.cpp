#include "bits/stdc++.h"

using namespace std;

struct Cmp {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        int g1 = abs(a.first - a.second);
        int g2 = abs(b.first - b.second);

        return g1 > g2;
    }
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, a, b;
    cin >> n >> a >> b;
    pair<int, int> arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr, arr + n, Cmp());

    long long ans = 0;
    for (auto p : arr) {
        if (a && b) {
            if (p.first < p.second) {
                a--;
                ans += p.first;
            } else {
                b--;
                ans += p.second;
            }
        } else if (a) {
            a--;
            ans += p.first;
        } else {
            b--;
            ans += p.second;
        }
    }

    cout << ans;
}
