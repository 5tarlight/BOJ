#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    unordered_set<int> s;

    int ans = 0;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (b == 1) {
            if (s.find(a) != s.end())
                ans++;
            s.insert(a);
        } else {
            if (s.find(a) == s.end())
                ans++;
            s.erase(a);
        }
    }

    ans += s.size();

    cout << ans;
}
