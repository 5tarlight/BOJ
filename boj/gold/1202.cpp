#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, k, cur;
priority_queue<int, vector<int>, less<int>> valuePq;
vector<pair<int, int>> gems;
vector<int> backpacks;

long long put(int back) {
    while (cur < n && gems[cur].first <= backpacks[back]) {
        valuePq.push(gems[cur].second);
        cur++;
    }

    if (valuePq.empty())
        return 0;
    else {
        int v = valuePq.top();
        valuePq.pop();
        return v;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        gems.emplace_back(a, b);
    }

    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;
        backpacks.push_back(c);
    }

    sort(gems.begin(), gems.end());
    sort(backpacks.begin(), backpacks.end());

    long long ans = 0;
    for (int i = 0; i < k; i++)
        ans += put(i);

    cout << ans;
}
