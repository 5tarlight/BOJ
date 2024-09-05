#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, q;
    long long m;
    cin >> n >> m >> q;

    map<int, vector<string>> group;
    map<string, long long> price;
    map<string, long long> bought;

    for (int i = 0; i < n; i++) {
        int g, p;
        string h;
        cin >> g >> h >> p;
        group[g].push_back(h);
        price[h] = p;
    }

    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            string a;
            int b;
            cin >> a >> b;
            if (m >= price[a] * b) {
                m -= price[a] * b;
                bought[a] += b;
            }
        } else if (op == 2) {
            string a;
            long long b;
            cin >> a >> b;
            b = min(bought[a], b);

            m += price[a] * b;
            bought[a] -= b;
        } else if (op == 3) {
            string a;
            int c;
            cin >> a >> c;
            price[a] += c;
        } else if (op == 4) {
            int d, c;
            cin >> d >> c;
            for (auto &i : group[d])
                price[i] += c;
        } else if (op == 5) {
            int d, e;
            cin >> d >> e;
            for (auto &i : group[d])
                price[i] = (price[i] * (100 + e) / 100 / 10) * 10;
        } else if (op == 6) {
            cout << m << '\n';
        } else {
            long long sum = 0;
            for (auto &i : bought)
                sum += price[i.first] * i.second;
            cout << sum + m << '\n';
        }
    }
}
