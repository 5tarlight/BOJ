#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); ios::sync_with_stdio(false); }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <class OStream, class T, class U> OStream &operator<<(OStream &os, const std::pair<T, U> &pa) { return os << '(' << pa.first << ',' << pa.second << ')'; }
#ifdef YEAHx4
#define dbg(x) std::cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#else
#define dbg(x) ((void)0)
#endif

using ll = long long;

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void egcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    ll x1, y1;
    egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
}

int main() {
    fio();

    while (true) {
        int a, b, d;
        cin >> a >> b >> d;
        if (a == 0 && b == 0 && d == 0) break;

        int g = gcd(a, b);
        int ap = a / g;
        int bp = b / g;
        int dp = d / g;

        ll x0, y0;
        egcd(ap, bp, x0, y0);
        ll xp = dp * x0;
        ll yp = dp * y0;

        auto cost = [&](ll k) {
            ll x = xp + k * bp;
            ll y = yp - k * ap;
            ll cnt = abs(x) + abs(y);
            ll mass = (ll)a * abs(x) + (ll)b * abs(y);
            return make_pair(cnt, mass);
        };

        vector<ll> can;
        auto add = [&](double k) {
            ll kf = floor(k);
            ll kc = ceil(k);
            can.push_back(kf);
            can.push_back(kc);
        };

        if (bp != 0) add(-(double)xp / bp);
        if (ap != 0) add((double)yp / ap);

        can.push_back(0);
        sort(can.begin(), can.end());
        can.erase(unique(can.begin(), can.end()), can.end());

        pair<ll, ll> best = { LLONG_MAX, LLONG_MAX };
        ll bk = 0;
        for (ll k : can) {
            auto cur = cost(k);
            if (cur < best) {
                best = cur;
                bk = k;
            }
        }

        ll x = xp + bk * bp;
        ll y = yp - bk * ap;
        cout << abs(x) << ' ' << abs(y) << '\n';
    }
}
