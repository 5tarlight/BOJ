#include "bits/stdc++.h"

using namespace std;

constexpr int MAX = 100000;

struct Line {
    long long a, b;
    double s;

    Line(long long _a, long long _b, double _s = 0)
        : a(_a), b(_b), s(_s) {}
};

double cross(const Line &a, const Line &b) {
    return (double)(a.b - b.b) / (a.a - b.a);
}

int a[MAX];
int b[MAX];
int n;
vector<Line> s;
long long dp[MAX];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 1; i < n; i++) {
        Line g(b[i - 1], dp[i - 1]);

        while (s.size() >= 1) {
            g.s = cross(g, s.back());

            if (g.s < s.back().s)
                s.pop_back();
            else
                break;
        }

        s.push_back(g);

        long long x = a[i];
        int pos = 0;

        int left = 0;
        int right = s.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (s[mid].s < x) {
                pos = mid;
                left = mid + 1;
            } else
                right = mid - 1;
        }

        dp[i] = s[pos].a * x + s[pos].b;
    }

    cout << dp[n - 1];
}
