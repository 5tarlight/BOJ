#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

using ll = long long;

int main() {
    fio();

    ll n;
    int m, k;
    cin >> n >> m >> k;

    unordered_map<ll, double> states;
    states[n] = 1.0;

    for (int i = 1; i <= k; i++) {
        unordered_map<ll, double> nxt;
        for (auto const &[cur, prob] : states) {
            if (cur == 0) {
                nxt[0] += prob;
                continue;
            }

            if (cur > m) {
                ll q = cur / m;
                ll r = cur % m;

                nxt[cur - q] += prob * (double)(m - r) / m;
                if (r > 0)
                    nxt[cur - q - 1] += prob * (double)r / m;
            } else {
                nxt[cur - 1] += prob * (double)cur / m;
                nxt[cur] += prob * (double)(m - cur) / m;
            }
        }

        states = move(nxt);
    }

    double ans = states.count(0) ? states[0] : 0.0;
    cout << fixed << setprecision(10) << 1 - ans;
}
