#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

char ch[20];
bool used[20];
int n;

void backtrack(int d, string s) {
    if (d == n) {
        cout << s << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        if (used[i] || (i > 0 && ch[i] == ch[i - 1] && !used[i - 1])) continue;
        used[i] = true;
        backtrack(d + 1, s + ch[i]);
        used[i] = false;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        n = s.size();
        for (int i = 0; i < n; i++)
            ch[i] = s[i];
        sort(ch, ch + n);

        backtrack(0, "");
    }
}
