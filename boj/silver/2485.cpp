#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int gaps[n - 1];

    int s;
    cin >> s;
    int g = -1;
    for (int i = 0; i < n - 1; i++) {
        int v;
        cin >> v;
        gaps[i] = v - s;
        s = v;

        if (g == -1)
            g = gaps[i];
        else
            g = gcd(max(g, gaps[i]), min(g, gaps[i]));
    }

    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        cnt += gaps[i] / g - 1;
    }

    cout << cnt;
}
