#include <iostream>
#include <algorithm>

using namespace std;

long long x, y;

struct Cmp {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        long long aRes = x * a.first - y * a.second;
        long long bRes = x * b.first - y * b.second;

        return aRes < bRes;
    }
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k >> x >> y;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a + n, Cmp());

    long long normal = k;
    long long fast = k;
    for (int i = 0; i < m; i++) {
        normal += a[i].first;
        fast -= a[i].second;
    }

    cout << normal * x + fast * y;
}
