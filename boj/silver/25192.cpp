#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    map<string, bool> m;
    int n;
    cin >> n;
    int cnt = 0;
    while (n--) {
        string s;
        cin >> s;

        if (s == "ENTER") {
            cnt += m.size();
            m.clear();
        } else if (m.find(s) == m.end()) {
            m[s] = true;
        }
    }

    cout << cnt + m.size();
}
