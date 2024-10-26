#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int x, sum = 0;
    for (int i = 0; i < 4; i++) {
        cin >> x;
        sum += x;
    }

    cout << sum / 60 << '\n' << sum % 60;
}
