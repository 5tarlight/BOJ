#include "bits/stdc++.h"

using namespace std;

struct Dp {
    int max;
    int min;
    int dist;
    int loc;
    int time;
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int mn = 0, mx = 0;
    tuple<int, int, int> data[n];
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        data[i] = { a, b, c };
    }

    sort(data, data + n);

    Dp dp[n + 1][2];
    dp[0][0] = dp[0][1] = { 0, 0, 0, 0, 0 };

    for (int i = 0; i < n; i++) {
        auto [t, s, e] = data[i - 1];
        dp[i + 1][0].time = t;
        int gap = t - dp[i][0].time;


    }
}
