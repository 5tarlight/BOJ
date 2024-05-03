#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n], b[n], c[n], d[n];
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];

    vector<long long> lsum, rsum;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            lsum.push_back(a[i] + b[j]);
            rsum.push_back(c[i] + d[j]);
        }
    }
    sort(rsum.begin(), rsum.end());

    long long ans = 0;
    for (int i = 0; i < lsum.size(); i++) {
        long long target = -lsum[i];
        auto range = equal_range(rsum.begin(), rsum.end(), target);
        ans += range.second - range.first;
    }

    cout << ans;
}
