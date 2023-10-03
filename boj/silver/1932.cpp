#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    vector<int> nums[500];
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            int in;
            cin >> in;
            nums[i].push_back(in);
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0)
                nums[i][j] += nums[i - 1][j];
            else if (j == n - 1)
                nums[i][j] += nums[i - 1][j - 1];
            else
                nums[i][j] += max(nums[i - 1][j - 1], nums[i - 1][j]);
        }
    }

    int m = -1;
    for (int i : nums[n - 1]) {
        if (i > m)
            m = i;
    }

    cout << m;
}
