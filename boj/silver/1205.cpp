#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n, p;
    long long ns;
    cin >> n >> ns >> p;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n == p && n > 0 && ns <= a[n - 1]) {
        cout << -1;
        return 0;
    }

    int cnt = 0;
    for (long long x : a) {
        if (x > ns) cnt++;
        else break;
    }

    cout << cnt + 1;
}
