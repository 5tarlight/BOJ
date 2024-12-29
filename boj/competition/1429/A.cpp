#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    unordered_set<string> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        m.insert(s);
    }

    for (int i = 0; i < n - 1; i++) {
        string s;
        cin >> s;
        m.erase(s);
    }

    for (auto s : m)
        cout << s;
}
