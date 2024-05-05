#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int ans = 0;

    int left = 0;
    while (n--) {
        int num;
        cin >> num;
        if (num <= left)
            left -= num;
        else {
            ans++;
            left = m - num;
        }
    }

    cout << ans;
}
