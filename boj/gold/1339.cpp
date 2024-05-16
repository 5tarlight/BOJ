#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long cnt[26] = { 0, };
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;

        long long digit = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            cnt[s[i] - 'A'] += digit;
            digit *= 10;
        }
    }

    sort(cnt, cnt + 26, greater<>());

    long long ans = 0;
    for (int i = 9; i >= 1; i--)
        ans += cnt[9 - i] * i;

    cout << ans;
}
