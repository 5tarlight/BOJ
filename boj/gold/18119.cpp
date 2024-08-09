#include <iostream>

using namespace std;

int toBit(string &s) {
    int ans = 0;
    for (char c : s)
        ans |= 1 << (c - 'a');
    return ans;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[i] = toBit(s);
    }

    int cur = 0b11111111111111111111111111;

    while (m--) {
        int o;
        char c;
        cin >> o >> c;

        if (o == 1)
            cur ^= 1 << (c - 'a');
        else
            cur |= 1 << (c - 'a');

        int cnt = 0;
        for (int b : a)
            if ((b & cur) == b)
                cnt++;
        cout << cnt << '\n';
    }
}
