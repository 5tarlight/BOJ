#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int cnt = 0;
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
            cnt++;
        }
    }

    cout << cnt << '\n';
    cnt = 0;
    max = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > max) {
            max = a[i];
            cnt++;
        }
    }

    cout << cnt;
}
