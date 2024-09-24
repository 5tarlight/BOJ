#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int c;
    cin >> c;
    string a, b;
    cin >> a >> b;
    int w = a.size() - c;

    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i] && c) {
            ans++;
            c--;
        } else if (a[i] != b[i] && w) {
            ans++;
            w--;
        }
    }

    cout << ans;
}

