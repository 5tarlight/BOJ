#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<string, int> m;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            m[s] = i;
        }

        int sec[n];
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            sec[i] = m[s];
        }
        pair<int, string> p[n];

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            p[i] = { sec[i], s };
        }

        sort(p, p + n);
        for (int i = 0; i < n; i++)
            cout << p[i].second << ' ';
        cout << '\n';
    }
}
