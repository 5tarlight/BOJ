#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

int main() {
    int s, t;
    cin >> s >> t;

    set<ll> visited;
    queue<pair<ll, string>> q;
    visited.insert(s);
    q.push({ s,  "" });

    if (s == t) {
        cout << 0;
        return 0;
    }

    while (!q.empty()) {
        auto [x, str] = q.front();
        q.pop();

        if (x * x > 0 && visited.find(x * x) == visited.end()) {
             visited.insert(x * x);
             q.push({ x * x, str + "*" });
             if (x * x == t) {
                 cout << str + "*";
                 return 0;
             }
        }

        if (visited.find(x + x) == visited.end()) {
            visited.insert(x + x);
            q.push({ x + x, str + "+" });
            if (x + x == t) {
                cout << str + "+";
                return 0;
            }
        }

        if (visited.find(0) == visited.end()) {
            visited.insert(0);
            q.push({ 0, str + "-" });
        }


        if (x != 0 && visited.find(1) == visited.end()) {
            visited.insert(1);
            q.push({ 1, str + "/" });
            if (1 == t) {
                cout << str + "/";
                return 0;
            }
        }
    }

    cout << -1;
}
