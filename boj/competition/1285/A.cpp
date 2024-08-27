#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    bool found[26] = { false, };
    int n;
    string s;
    cin >> n >> s;
    string ans;
    int cnt = 0;
    for (char ch : s) {
        if (found[ch - 'a'])
            cnt++;
        else {
            ans += ch;
            found[ch - 'a'] = true;
        }
    }

    ans = to_string(1906 + n) + ans + to_string(cnt + 4);

    cout << "smupc_";
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
}
