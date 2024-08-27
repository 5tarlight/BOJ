#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool isIn(int a, int b) {
    return b >= a && b >= -a;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<long long> dist;
    int foul = 0;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (isIn(a, b)) {
            dist.push_back(1LL * a * a + 1LL * b * b);
        } else {
            foul++;
        }
    }

    sort(dist.begin(), dist.end());

    int q;
    cin >> q;

    while (q--) {
        int r;
        cin >> r;

        int in = upper_bound(dist.begin(), dist.end(), 1LL * r * r) - dist.begin();
        int out = dist.size() - in;

        cout << foul << ' ' << in << ' ' << out << '\n';
    }
}

