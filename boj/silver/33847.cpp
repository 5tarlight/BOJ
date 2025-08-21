#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n, c;
    cin >> n >> c;

    struct Fish { int x, s; long long w; };
    vector<Fish> fish(n);
    int ss = 0;
    for (int i = 0; i < n; i++) {
        cin >> fish[i].x >> fish[i].s >> fish[i].w;
        ss += fish[i].x;
    }

    sort(fish.begin(), fish.end(), [](const Fish &a, const Fish &b) {
        return a.s > b.s;
    });

    long long ans = 0;
    for (int k = 0; k <= ss; k++) {
        int b = k;
        long long gain = 0;

        for (auto &f : fish) {
            if (b >= f.x) {
                b -= f.x;
                gain += f.w;
            }
        }

        long long profit = gain - 1LL * k * c;
        if (profit > ans) {
            ans = profit;
        }
    }

    cout << ans;
}
