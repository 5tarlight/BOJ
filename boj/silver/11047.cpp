#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int coin[n];
    for (int i = 0; i < n; i++)
        cin >> coin[i];

    int i = n - 1;
    int cnt = 0;
    while (k != 0) {
        if (coin[i] <= k) {
            cnt++;
            k -= coin[i];
        } else {
            i--;
        }
    }

    cout << cnt;
}
