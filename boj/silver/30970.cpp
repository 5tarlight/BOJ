#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

bool cmp1(pii &p1, pii &p2) {
    if (p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first > p2.first;
}

bool cmp2(pii &p1, pii &p2) {
    if (p1.second == p2.second)
        return p1.first > p2.first;
    return p1.second < p2.second;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    pii a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    sort(a, a + n, cmp1);
    cout << a[0].first << ' ' << a[0].second << ' ';
    cout << a[1].first << ' ' << a[1].second;

    cout << '\n';

    sort(a, a + n, cmp2);
    cout << a[0].first << ' ' << a[0].second << ' ';
    cout << a[1].first << ' ' << a[1].second;
}
