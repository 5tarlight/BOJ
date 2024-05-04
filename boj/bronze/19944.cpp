#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    if (m <= 2)
        cout << "NEWBIE!";
    else if (m <= n)
        cout << "OLDBIE!";
    else
        cout << "TLE!";
}
