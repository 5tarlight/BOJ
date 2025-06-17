#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int tmp = sqrt(n);
        if (tmp * tmp == n)
            cout << "1\n";
        else
            cout << "0\n";
    }
}
