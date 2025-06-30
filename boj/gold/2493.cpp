#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n; cin >> n;
    stack<pair<int, int>> s; // {index, height}
    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++) {
        int h; cin >> h;
        while (!s.empty() && s.top().second < h)
            s.pop();
        if (!s.empty())
            ans[i] = s.top().first + 1;
        s.push({i, h});
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}
