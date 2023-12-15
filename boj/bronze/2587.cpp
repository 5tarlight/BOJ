#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int nums[5];
    int sum = 0;
    for (int& num : nums) {
        cin >> num;
        sum += num;
    }

    sort(nums, nums + 5);

    cout << sum / 5 << '\n';
    cout << nums[2];
}
