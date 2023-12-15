#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int nums[n];
    for (int& num : nums)
        cin >> num;

    sort(nums, nums + n);

    cout << nums[n - k];
}
