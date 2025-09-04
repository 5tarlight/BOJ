#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int c(long long n, int f) {
    int ans = 0;
    if (n == 0) return 0;
    while (n % f == 0) {
        ans++;
        n /= f;
    }
    return ans;
}

int cmp(long long a, long long b) {
    int fa = c(a, 3);
    int fb = c(b, 3);

    if (fa != fb) return fa > fb;
    else return a < b;
}

int main() {
    fio();

    int n; cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n, cmp);

    for (int i = 0; i < n; i++) cout << a[i] << " ";
}
