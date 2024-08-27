#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int x, s;
    cin >> x >> s;

    bool ok = false;
    while (n--) {
        int c, p;
        cin >> c >> p;
        if (c <= x && p > s)
            ok = true;
    }

    if (ok)
        cout << "YES";
    else
        cout << "NO";
}
