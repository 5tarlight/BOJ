#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int nums[10];
vector<int> set;
bool used[10'001];

void backtrack(int d) {
    if (d == m) {
        for (int i = 0; i < m; i++)
            cout << nums[i] << ' ';
        cout << '\n';
        return;
    }

    int lastDigit = 0;
    for (int i = 0; i < set.size(); i++) {
        if (used[i] || set[i] == lastDigit)
            continue;

        nums[d] = set[i];
        lastDigit = set[i];
        used[i] = true;

        backtrack(d + 1);

        used[i] = false;
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
