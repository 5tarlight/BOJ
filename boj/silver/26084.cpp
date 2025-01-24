#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int n;
    cin >> n;
    int cnt[26] = {0};
    int minus[26] = {0};
    while (n--) {
        string x;
        cin >> x;
        cnt[x[0] - 'A']++;
    }

    long long ans = 1;
    long long div = 1;
    for (int i = 0; i < 3; i++) {
        int idx = s[i] - 'A';
        ans *= cnt[idx] - minus[idx];
        minus[idx]++;
        div *= minus[idx];
    }

    cout << ans / div;
}
