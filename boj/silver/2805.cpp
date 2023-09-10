#include <iostream>

using namespace std;

int n, m, v[1'000'000];

bool check(const int mid) {
    unsigned long long sum = 0;

    for (int i = 0; i < n; i++) {
        if (v[i] > mid)
            sum += v[i] - mid;
    }

    return sum >= m;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int lo = 0, hi = 1e9;

    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid))
            lo = mid;
        else
            hi = mid;
    }

    cout << lo;
}
