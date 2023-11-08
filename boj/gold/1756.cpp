#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int d, n;
    cin >> d >> n;
    int oven[d];
    int dough[n];
    for (int i = 0; i < d; i++) {
        cin >> oven[i];

        if (i > 0 && oven[i] > oven[i - 1])
            oven[i] = oven[i - 1];
    }
    for (int i = 0; i < n; i++)
        cin >> dough[i];

    int cnt = 0;
    int depth;
    for (int i = d - 1; i >= 0; i--) {
        if (oven[i] < dough[cnt])
            continue;
        else {
            cnt++;
            if (cnt == n) {
                depth = i + 1;
                break;
            }
        }
    }

    if (cnt == n)
        cout << depth;
    else
        cout << 0;
}
