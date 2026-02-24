#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    long long n; cin >> n;
    auto ans = n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 120;
    cout << ans;
}
