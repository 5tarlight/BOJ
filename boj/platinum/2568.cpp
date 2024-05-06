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
    pair<int, int> a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a + n);

    vector<int> lis;
    int pos[n];
    lis.push_back(a[0].second);
    pos[0] = 0;
    for (int i = 1; i < n; i++) {
        if (lis.back() < a[i].second) {
            lis.push_back(a[i].second);
            pos[i] = lis.size() - 1;
        } else {
            int idx = lower_bound(lis.begin(), lis.end(), a[i].second) - lis.begin();
            lis[idx] = a[i].second;
            pos[i] = idx;
        }
    }

    cout << n - lis.size() << '\n';

    vector<int> removes;
    int target = lis.size() - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (pos[i] == target)
            target--;
        else
            removes.push_back(a[i].first);
    }

    sort(removes.begin(), removes.end());
    for (int r : removes)
        cout << r << '\n';
}
