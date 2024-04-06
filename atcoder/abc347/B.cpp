#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    map<string, bool> m;

    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        string temp;
        for (int j = i; j < s.size(); j++) {
            temp += s[j];
            if (!m[temp]) {
                m[temp] = true;
                ans++;
            }
        }
    }

    cout << ans;
}
