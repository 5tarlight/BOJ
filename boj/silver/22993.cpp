#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    long long atk[n];
    long long me;
    cin >> me;
    for (int i = 0; i < n - 1; i++)
        cin >> atk[i];

    sort(atk, atk + n - 1);

    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
        if (atk[i] < me)
            me += atk[i];
        else {
            ok = false;
            break;
        }
    }

    if (ok)
        cout << "Yes";
    else
        cout << "No";
}
