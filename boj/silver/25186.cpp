#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n];
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if (n == 1 && a[0] == 1) {
        cout << "Happy";
        return 0;
    }

    bool ok = true;
    for (int i = 0; i < n; i++)
        if (sum < 2 * a[i])
            ok = false;

    if (ok)
        cout << "Happy";
    else
        cout << "Unhappy";
}
