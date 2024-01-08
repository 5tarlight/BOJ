#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void allSum(int left, int right, vector<int> &sums, vector<int> &a, int cur) {
    if (left > right)
        sums.push_back(cur);
    else {
        allSum(left + 1, right, sums, a, cur);
        allSum(left + 1, right, sums, a, cur + a[left]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    vector<int> left, right;
    int n, c;
    cin >> n >> c;

    for (int i = 0; i < (n + 1) / 2; i++) {
        int num;
        cin >> num;
        left.push_back(num);
    }
    for (int i = 0; i < n / 2; i++) {
        int num;
        cin >> num;
        right.push_back(num);
    }

    vector<int> leftSum, rightSum;
    allSum(0, left.size() - 1, leftSum, left, 0);
    allSum(0, right.size() - 1, rightSum, right, 0);

    sort(leftSum.begin(), leftSum.end());
    sort(rightSum.begin(), rightSum.end());

    long long cnt = 0;
    for (int s : leftSum) {
        long long start = lower_bound(rightSum.begin(), rightSum.end(), c - s) - rightSum.begin();
        long long end = upper_bound(rightSum.begin(), rightSum.end(), c - s) - rightSum.begin();
        cnt += end - start;
    }

    if (c == 0)
        cnt--;
    cout << cnt;
}
