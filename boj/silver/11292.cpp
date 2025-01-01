#include "bits/stdc++.h"

using namespace std;

struct Cmp {
    bool operator()(pair<string, double> a, pair<string, double> b) {
        return a.second > b.second;
    }
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<pair<string, double>> v;
        for (int i = 0; i < n; i++) {
            string s;
            double d;
            cin >> s >> d;
            v.push_back({ s, d });
        }

        stable_sort(v.begin(), v.end(), Cmp());

        double target = v[0].second;
        for (int i = 0; i < v.size(); i++) {
            if (v[i].second != target) break;
            cout << v[i].first << ' ';
        }
        cout << '\n';
    }
}
