#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n];
    for (int i = n - 1; i >= 0; i--)
        cin >> a[i];

    vector<int> v;
    v.push_back(a[0]);

    for (int i = 1; i < n; i++) {
        if (a[i] > v.back())
            v.emplace_back(a[i]);
        else {
            int idx = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            v[idx] = a[i];
        }
    }

    cout << n - v.size();
}
