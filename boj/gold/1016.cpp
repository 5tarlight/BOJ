#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long s, e;
    cin >> s >> e;
    bool filter[e - s + 1];
    fill(filter, filter + (e - s + 1), true);

    long long ans = e - s + 1;
    for (long long i = 2; i * i <= e; i++) {
        long long sq = i * i;
        long long mult = s / sq;

        if (s % sq != 0)
            mult++;

        while (mult * sq <= e) {
            if (filter[mult * sq - s]) {
                filter[mult * sq - s] = false;
                ans--;
            }
            mult++;
        }
    }

    cout << ans;
}
