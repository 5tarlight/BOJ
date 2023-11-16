#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int nums[n];
    for (int i = 0; i < n; i++)
        nums[i] = 0;

    while (m--) {
        int i, j, k;
        cin >> i >> j >> k;
        for (int s = i - 1; s < j; s++)
            nums[s] = k;
    }

    for (int v : nums)
        cout << v << ' ';
}
