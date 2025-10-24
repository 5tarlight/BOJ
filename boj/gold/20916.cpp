#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

typedef long long ll;

int main() {
    fio();

    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

       vector<int> good = {
               202021, 20202021, 202002021, 202012021,
               202022021, 202032021, 202042021, 202052021,
               202062021, 202072021, 202082021, 202092021
       };

       sort(a, a + n);

       long long ans = 0;
       for (int i = 0; i < n; i++) {
           for (auto g : good) {
               int tmp = g - a[i];
               int s = lower_bound(a + i + 1, a + n, tmp) - a;
               int e = upper_bound(a + i + 1, a + n, tmp) - a;
               ans += e - s;
           }
       }

       cout << ans << '\n';
    }
}
