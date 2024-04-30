#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        while (n && k) {
            n /= 2;
            k--;
        }

        cout << (n + 1) / 2 << '\n';
    }
}
