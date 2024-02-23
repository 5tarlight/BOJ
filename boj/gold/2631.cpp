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
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> lis;
    lis.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i] > lis.back())
            lis.push_back(a[i]);
        else {
            int idx = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
            lis[idx] = a[i];
        }
    }

    cout << n - lis.size();
}
