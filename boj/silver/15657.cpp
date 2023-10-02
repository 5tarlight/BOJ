#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int nums[10];
vector<int> set;

void backtrack(int d) {
    if (d == m) {
        for (int i = 0; i < m; i++)
            cout << nums[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i : set) {
        if (d > 0 && i < nums[d - 1])
            continue;

        nums[d] = i;
        backtrack(d + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int n;
        cin >> n;
        set.push_back(n);
    }

    sort(set.begin(), set.end());
    backtrack(0);
}
