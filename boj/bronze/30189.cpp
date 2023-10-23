#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int cnt = 0;
    for (int i = 0; i <= m + n; i++) {
        for (int a = 0; a <= n; a++) {
            if (i - a <= m && i - a >= 0) {
                cnt++;
            }
        }
    }

    cout << cnt;
}
