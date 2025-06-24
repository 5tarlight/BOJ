#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n, m;
    cin >> n >> m;
    int six = 1e9, one = 1e9;
    while (m--) {
        int a, b;
        cin >> a >> b;
        six = min(six, a);
        one = min(one, b);
    }

    int ans = 0;
    if (six < one * 6) {
        ans += (n / 6) * six;
        n %= 6;

        if (n * one < six) {
            ans += n * one;
        } else {
            ans += six;
        }
    } else {
        ans += n * one;
    }

    cout << ans;
}
