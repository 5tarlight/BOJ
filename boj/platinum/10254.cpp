#include "bits/stdc++.h"

using namespace std;

struct P {
    int x, y, p, q;

    bool operator<(const P& a) const {
        if (1LL * p * a.q != 1LL * q * a.p)
            return 1LL * p * a.q - 1LL * q * a.p > 0;
        if (y != a.y) return y < a.y;
        return x < a.x;
    }
};

using ll = long long;

ll ccw(P& a, P& b, P& c) {
    return 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (b.y - a.y) * (c.x - a.x);
}

ll dist(P& a, P& b) {
    return 1LL * (b.x - a.x) * (b.x - a.x) + 1LL * (b.y - a.y) * (b.y - a.y);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<P> v(n);
        stack<int> s;

        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            v[i] = { x, y };
        }

        sort(v.begin(), v.end());

        for (int i = 1; i < n; i++) {
            v[i].p = v[i].x - v[0].x;
            v[i].q = v[i].y - v[0].y;
        }

        sort(v.begin() + 1, v.end());

        s.push(0);
        s.push(1);

        int nxt = 2;
        while (nxt < n) {
            while (s.size() >= 2) {
                int nd, st;
                nd = s.top();
                s.pop();
                st = s.top();

                if (ccw(v[st], v[nd], v[nxt]) > 0) {
                    s.push(nd);
                    break;
                }
            }

            s.push(nxt++);
        }

        vector<P> hull;
        while (!s.empty()) {
            hull.push_back(v[s.top()]);
            s.pop();
        }

        ll maxD = 0;
        P a1, a2;
        int j = 1;

        for (int i = 0; i < hull.size(); i++) {
            int in = (i + 1) % hull.size();
            while (true) {
                int jn = (j + 1) % hull.size();
                P vi, vj;

                vi.x = hull[in].x - hull[i].x;
                vi.y = hull[in].y - hull[i].y;
                vj.x = hull[jn].x - hull[j].x;
                vj.y = hull[jn].y - hull[j].y;

                P tmp = { 0, 0 };

                if (ccw(tmp, vi, vj) < 0) j = jn;
                else break;
            }

            ll d = dist(hull[i], hull[j]);

            if (d > maxD) {
                maxD = d;
                a1 = hull[i];
                a2 = hull[j];
            }
        }

        cout << a1.x << ' ' << a1.y << ' ' << a2.x << ' ' << a2.y << '\n';
    }
}
