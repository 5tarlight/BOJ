#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_set<int> s;
    int n;
    cin >> n;
    int remain = 1;
    int ans = 1;

    while (remain % n != 0) {
        if (s.count(remain)) {
            cout << -1 << endl;
            return 0;
        }

        s.insert(remain);
        remain = (remain * 10 + 1) % n;
        ans++;
    }

    cout << ans << endl;
}
