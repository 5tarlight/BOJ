#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    int cnt[53];
    fill(cnt, cnt + 53, 0);
    while (n--) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    cin.ignore();
    getline(cin, s);

    for (char ch : s) {
        if (ch >= 'a' && ch <= 'z') {
            int target = ch - 'a' + 27;
            if (cnt[target] == 0) {
                cout << "n";
                return 0;
            }
            cnt[target]--;
        } else if (ch >= 'A' && ch <= 'Z') {
            int target = ch - 'A' + 1;
            if (cnt[target] == 0) {
                cout << "n";
                return 0;
            }
            cnt[target]--;
        } else {
            if (cnt[0] == 0) {
                cout << "n";
                return 0;
            }
            cnt[0]--;
        }
    }

    cout << "y";
}
