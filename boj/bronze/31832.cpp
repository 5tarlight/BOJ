#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        if (s.size() > 10) continue;

        bool isNum = true;
        int l = 0, u = 0;

        for (char ch : s) {
            if (ch == '-') {
                isNum = false;
                continue;
            } else if (ch >= '0' && ch <= '9') continue;
            else {
                isNum = false;
                if (ch >= 'a' && ch <= 'z')
                    l++;
                else
                    u++;
            }
        }

        if (isNum || u > l) continue;

        cout << s;
        return 0;
    }
}
