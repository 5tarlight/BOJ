#include "bits/stdc++.h"

using namespace std;
using ll = long long;

struct Line {
    ll m, c;
    ll get(ll x) { return m * x + c; }
    long double inter(Line& l) {
        return (long double)(c - l.c) / (l.m - m);
    }
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    ll a, b, c;
    cin >> a >> b >> c;

    vector<ll> v(n + 1, 0);
    vector<ll> p(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        p[i] = v[i] + p[i - 1];
    }

    deque<Line> dq;
    dq.push_front({ 0, 0 });

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        while (dq.size() >= 2 && dq[0].get(p[i]) <= dq[1].get(p[i]))
            dq.pop_front();

        ans = dq.front().get(p[i]);

        Line cur = {
                -2LL * a * p[i],
                a * p[i] * p[i] - b * p[i] + ans + a * p[i] * p[i] + b * p[i] + c
        };

        while (dq.size() >= 2 && cur.inter(dq.back()) <= dq.back().inter(dq[dq.size() - 2]))
            dq.pop_back();

        dq.push_back(cur);
    }

    cout << ans + a * p[n] * p[n] + b * p[n] + c;
}
