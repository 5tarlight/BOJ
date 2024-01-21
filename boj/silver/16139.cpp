#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    map<char, vector<int>> cnt;
    string s;
    cin >> s;
    for (char i = 'a'; i <= 'z'; i++)
        cnt[i] = vector<int>(s.size());

    for (int i = 0; i < s.size(); i++) {
        for (char j = 'a'; j <= 'z'; j++) {
            if (j == s[i]) {
                if (i == 0)
                    cnt[j][i] = 1;
                else
                    cnt[j][i] = cnt[j][i - 1] + 1;
            } else {
                if (i == 0)
                    cnt[j][i] = 0;
                else
                    cnt[j][i] = cnt[j][i - 1];
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        char ch;
        int l, r;
        cin >> ch >> l >> r;

        if (l == 0)
            cout << cnt[ch][r] << '\n';
        else
            cout << cnt[ch][r] - cnt[ch][l - 1] << '\n';
    }
}
