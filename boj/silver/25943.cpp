#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int left = 0;
    int right = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (left == right || left < right)
            left += x;
        else
            right += x;
    }

    int target = left < right ? right - left : left - right;
    long long ans = 0;
    int b[] = { 100, 50, 20, 10, 5, 2, 1 };
    for (int i = 0; i < 7; i++) {
        ans += target / b[i];
        target %= b[i];
    }

    cout << ans;
}
