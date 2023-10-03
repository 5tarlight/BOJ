#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int nums[n + 1];
    vector<int> l;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < n; i++) {
        if (l.empty())
            l.push_back(nums[i]);
        else {
            if (l[l.size() - 1] < nums[i])
                l.push_back(nums[i]);
            else
                *(lower_bound(l.begin(), l.end(), nums[i])) = nums[i];
        }
    }

    cout << l.size();
}
