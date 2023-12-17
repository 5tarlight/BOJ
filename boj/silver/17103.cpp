#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    bool filter[1'000'001];
    fill(filter, filter + 1000001, true);
    filter[0] = filter[1] = false;
    for (int i = 2; i < 1'000'001; i++) {
        if (filter[i]) {
            for (int j = 2; j * i < 1'000'001; j++)
                filter[i * j] = false;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int cnt = 0;
        int n;
        cin >> n;
        for (int i = 2; 2 * i <= n; i++)
            if (filter[i] && filter[n - i])
                cnt++;
        cout << cnt << '\n';
    }
}
