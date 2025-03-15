#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'p' && i < n - 1 && s[i + 1] == 'i') {
            i++;
            continue;
        } else if (s[i] == 'k' && i < n - 1 && s[i + 1] == 'a') {
            i++;
            continue;
        } else if (s[i] == 'c' && i < n - 2 && s[i + 1] == 'h' && s[i + 2] == 'u') {
            i += 2;
            continue;
        } else {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}
