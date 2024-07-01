#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        bool used[26] = { false, };
        for (char ch : s) {
            used[ch - 'A'] = true;
        }
        int ans = 0;

        for (int i = 0; i < 26; i++) {
            if (!used[i])
                ans += 65 + i;
        }

        cout << ans << '\n';
    }
}
