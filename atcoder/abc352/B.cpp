#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;

    int idx = 0;
    for (int i = 0; i < t.size(); i++) {
        if (s[idx] == t[i]) {
            cout << i + 1 << ' ';
            idx++;
        }
    }
}
