#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> ans;
    ans.push_back(a[0]);

    for (int i = 1; i < n; i++) {
        if (a[i] > ans.back())
            ans.push_back(a[i]);
        else {
            int idx = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[idx] = a[i];
        }
    }

    cout << ans.size();
}
