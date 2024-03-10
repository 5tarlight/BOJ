#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string s[n];
    string a[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        a[i] = s[i];
    }

    sort(s, s + n);

    bool increasing = true;
    bool decreasing = true;

    for (int i = 0; i < n; i++)
        if (s[i] != a[i]) {
            increasing = false;
            break;
        }

    for (int i = n - 1; i >= 0; i--)
        if (s[i] != a[n - i - 1]) {
            decreasing = false;
            break;
        }

    if (increasing) {
        cout << "INCREASING";
    } else if (decreasing) {
        cout << "DECREASING";
    } else {
        cout << "NEITHER";
    }
}
