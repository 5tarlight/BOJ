#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    map<string, int> cnt;
    string s;
    int total = 0;
    while (getline(cin, s)) {
        cnt[s]++;
        total++;
    }

    cout.precision(4);
    cout << fixed;

    for (const auto& [s, c] : cnt)
        cout << s << " " << 100.0 * c / (double)total << '\n';
}
