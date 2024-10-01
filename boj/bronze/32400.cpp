#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a[20];
    for (int i = 0; i < 20; i++)
        cin >> a[i];

    int alice;
    for (int i = 0; i < 20; i++) {
        if (a[i] == 20) {
            alice = a[i];
            if (i == 0)
                alice += a[19];
            else
                alice += a[i - 1];
            if (i == 19)
                alice += a[0];
            else
                alice += a[i + 1];
        }
    }

    if ((double)alice / 3.0 > 10.5)
        cout << "Alice";
    else
        cout << "Bob";
}
