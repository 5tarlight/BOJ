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
        unordered_map<string, int> m;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            m[s] = i;
        }

        int sol[1000];
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            sol[m[s]] = i;
        }

        string ans[n];
        for (int i = 0; i < n; i++)
            cin >> ans[i];
        for (int i = 0; i < n; i++)
            cout << ans[sol[i]] << ' ';
        cout << '\n';
    }
}
