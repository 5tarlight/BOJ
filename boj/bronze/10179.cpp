#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int t; cin >> t;
    while (t--) {
        double x; cin >> x;
        cout << '$' << fixed << setprecision(2) << x * 0.8 << '\n';
    }
}
