#include <iostream>
#include <vector>

using namespace std;

int bsearch(vector<int> &a, int k) {
    int s = 0;
    int e = a.size() - 1;

    while (s < e) {
        int mid = s + (e - s) / 2;

        if (a[mid] >= k)
            e = mid;
        else
            s = mid + 1;
    }

    return e;
}

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
            int idx = bsearch(ans, a[i]);
            ans[idx] = a[i];
        }
    }

    cout << ans.size();
}
