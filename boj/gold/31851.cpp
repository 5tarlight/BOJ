#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

typedef pair<long long, long long> pii;

long long ccw(pii &p1, pii &p2, pii &p3) {
    auto [x1, y1] = p1;
    auto [x2, y2] = p2;
    auto [x3, y3] = p3;

    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

pii a[50];

// l 이 ijk 안에 있는지
bool isIn(int i, int j, int k, int l) {
    long long c1 = ccw(a[i], a[j], a[l]);
    long long c2 = ccw(a[j], a[k], a[l]);
    long long c3 = ccw(a[k], a[i], a[l]);

    return (c1 >= 0 && c2 >= 0 && c3 >= 0) || (c1 <= 0 && c2 <= 0 && c3 <= 0);
}

bool ok(int i, int j, int k, int l) {
    if (isIn(i, j, k, l)) return false;
    if (isIn(i, j, l, k)) return false;
    if (isIn(i, k, l, j)) return false;
    if (isIn(j, k, l, i)) return false;
    return true;
}

int main() {
    fio();

    int n; cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
                for (int l = k + 1; l < n; l++)
                    if (ok(i, j, k, l))
                        ans++;

    cout << ans;
}
