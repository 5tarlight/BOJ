#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool canConnect(const string &a, const string &b) {
    int a_len = a.length();
    int b_len = b.length();
    int min_len = min(a_len, b_len);

    for (int len = 1; len <= min_len; ++len) {
        if (a.substr(a_len - len) == b.substr(0, len)) {
            return true;
        }
    }

    return false;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (canConnect(s[i], s[j]) || canConnect(s[j], s[i])) {
                ans++;
            }
        }
    }

    cout << ans;
    return 0;
}
