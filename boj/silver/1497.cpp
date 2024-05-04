#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int ans = 1e9;
int songs = 0;
long long bit[10];
int n, m;

void backtrack(int idx, long long s, int cnt) {
    if (idx == n) {
        if (s == 0)
            return;

        int song = 0;
        for (int i = 0; i < m; i++)
            if (s & (1L << i))
                song++;

        if (song == songs)
            ans = min(ans, cnt);
        else if (song > songs) {
            ans = cnt;
            songs = song;
        }
        return;
    }

    backtrack(idx + 1, s | bit[idx], cnt + 1);
    backtrack(idx + 1, s, cnt);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s, v;
        cin >> s >> v;

        for (int j = 0; j < v.size(); j++)
            if (v[j] == 'Y')
                bit[i] |= (1L << j);
    }

    backtrack(0, 0, 0);

    if (ans == 1e9)
        cout << -1;
    else
        cout << ans;
}
