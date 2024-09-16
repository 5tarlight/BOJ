#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    set<pair<int, int>> p;

    while (n--) {
        int x, y;
        cin >> x >> y;
        int g = gcd(abs(x), abs(y));
        p.insert({ x / g, y / g });
    }

    cout << p.size();
}
