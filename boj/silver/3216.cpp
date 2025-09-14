#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n; cin >> n;
    int d[n], v[n];
    for (int i = 0; i < n; i++)
        cin >> d[i] >> v[i];

    int download = 0;
    int play = 0;
    int wait = 0;
    for (int i = 0; i < n; i++) {
        download += v[i];
        wait = max(wait, download - play);
        play += d[i];
    }

    cout << wait;
}
