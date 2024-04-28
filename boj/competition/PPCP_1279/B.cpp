#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int ans = 0;

    while (n--) {
        int a[3];
        cin >> a[0] >> a[1] >> a[2];

        if (a[0] == -1)
            continue;
        int prev = a[0];
        bool flag = false;
        for (int i = 1; i < 3; i++) {
            if (flag && a[i] != -1)
                break;
            if (!flag && a[i] != -1 && prev > a[i])
                break;

            if (i == 2) {
                ans++;
                break;
            }

            if (a[i] == -1) {
                flag = true;
                continue;
            }

            prev = a[i];

        }
    }

    cout << ans;
}
