#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int fee[n + 1][3];
    fee[0][0] = 0;
    fee[0][1] = 0;
    fee[0][2] = 0;

    for (int i = 1; i <= n; i++) {
        int r, g, b;
        cin >> r >> g >> b;

        fee[i][0] = min(fee[i - 1][1], fee[i - 1][2]) + r;
        fee[i][1] = min(fee[i - 1][0], fee[i - 1][2]) + g;
        fee[i][2] = min(fee[i - 1][0], fee[i - 1][1]) + b;
    }

    cout << min(fee[n][0], min(fee[n][1], fee[n][2]));
}
