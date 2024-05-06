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
    lis.push_back(a[0].second);
    for (int i = 1; i < n; i++) {
        if (lis.back() < a[i].second)
            lis.push_back(a[i].second);
        else {
            int idx = lower_bound(lis.begin(), lis.end(), a[i].second) - lis.begin();
            lis[idx] = a[i].second;
        }
    }

    cout << n - lis.size() << '\n';
}
