#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, d;
    cin >> n >> d;
    double a[4];
    for (int i = 0; i < 4; i++)
        cin >> a[i];

    double happy, unhappy;
    if (d == 0) {
        happy = a[0];
        unhappy = a[1];
    } else {
        happy = a[2];
        unhappy = a[3];
    }

    for (int i = 1; i < n; i++) {
        double nHappy, nUnhappy;

        nHappy = happy * a[0] + unhappy * a[2];
        nUnhappy = happy * a[1] + unhappy * a[3];

        happy = nHappy;
        unhappy = nUnhappy;
    }

    cout << (int)(1000 * happy) << endl;
    cout << (int)(1000 * unhappy) << endl;
}
