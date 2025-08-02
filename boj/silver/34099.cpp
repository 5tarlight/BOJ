#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;

        if (k != 1)
            for (int i = 1; i <= n; i++)
                cout << i << " ";
        else {
            if (n <= 3) cout << -1;
            else {
                for (int i = 2; i <= n; i += 2)
                    cout << i << " ";
                for (int i = 1; i <= n; i += 2)
                    cout << i << " ";
            }
        }

        cout << "\n";
    }
}
