#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string t;
    cin >> t;
    int n;
    cin >> n;

    int ans = 0;
    while (n--) {
        string s;
        cin >> s;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == t[0]) {
                bool found = true;
                for (int j = 1; j < t.size(); j++) {
                    if (i + j >= s.size() && s[i + j - s.size()] != t[j]) {
                        found = false;
                        break;
                    } else if (i + j < s.size() && s[i + j] != t[j]) {
                        found = false;
                        break;
                    }
                }

                if (found) {
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans;
}
