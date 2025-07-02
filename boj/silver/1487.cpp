#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

using ll = long long;

int main() {
    fio();

    int n; cin >> n;

    vector<pair<ll, ll>> a(n);
    vector<ll> prices;
    prices.reserve(n);

    for (int i = 0; i < n; i++) {
        ll will, ship;
        cin >> will >> ship;
        a[i] = { will, ship };
        prices.push_back(will);
    }

    sort(prices.begin(), prices.end());
    prices.erase(unique(prices.begin(), prices.end()), prices.end());

    ll bestProfit = 0;
    ll bestPrice = 0;

    for (ll p : prices) {
        ll cnt = 0;
        ll sumShip = 0;
        for (const auto& [will, ship] : a) {
            if (will >= p && ship <= p) {
                cnt++;
                sumShip += ship;
            }
        }

        ll profit = cnt * p - sumShip;
        if (profit > bestProfit || (profit == bestProfit && p < bestPrice)) {
            bestProfit = profit;
            bestPrice = p;
        }
    }

    if (bestProfit <= 0)
        cout << 0;
    else
        cout << bestPrice;
}
