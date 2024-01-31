#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    map<int, string> m;
    pair<int, int> a[n];

    for (int i = 0; i < n; i++) {
        int h;
        string e;
        cin >> h >> e;
        m[i] = e;
        a[i] = make_pair(h, i);
    }

    sort(a, a + n);

    for (auto &p : a) {
        cout << p.first << ' ' << m[p.second] << '\n';
    }
}
