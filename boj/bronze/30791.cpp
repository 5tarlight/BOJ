#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        int c;
        cin >> c;
        if (n > c && n - c <= 1000)
            ans++;
    }

    cout << ans;
}
