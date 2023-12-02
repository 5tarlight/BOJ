#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int cnt = 0;
    int l;
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            l = i;
            cnt++;
        }

        if (cnt == k)
            break;
    }

    if (cnt == k)
        cout << l;
    else
        cout << 0;
}
