#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int a[n];
    int position[n];
    vector<int> lis;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (lis.empty() || lis.back() < a[i]) {
            lis.push_back(a[i]);
            position[i] = lis.size() - 1;
        } else {
            int idx = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
            lis[idx] = a[i];
            position[i] = idx;
        }
    }

    vector<int> ans;
    int target = lis.size() - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (position[i] == target) {
            target--;
            ans.push_back(a[i]);
        }
    }

    cout << lis.size() << '\n';
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << ' ';
}
