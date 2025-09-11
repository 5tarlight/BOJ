#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int ans = 0;

void fibo(int x) {
    if (x <= 2) ans++;
    else fibo(x - 1), fibo(x - 2);
}

int main() {
    fio();

    int n;
    cin >> n;
    fibo(n);

    cout << ans << ' ' << n - 2;
}
