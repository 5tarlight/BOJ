#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for (int i = 1; i <= n; i++) {
        int s, e;
        cin >> s >> e;
        a.push_back({ s, i });
        a.push_back({ e + 1, -i });
    }

    sort(a.begin(), a.end());

    int prev = 1e9 + 1;
    int cnt = -1;
    for (int i = 0; i < a.size(); i++) {
        if (prev != a[i].first)
            cnt++;

        prev = a[i].first;
        a[i].first = cnt;
        swap(a[i].first, a[i].second);
    }

    cnt = 0;
    int maxCnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i].first > 0) cnt++;
        else cnt--;

        if (i < a.size() - 1 && a[i].second == a[i + 1].second) continue;
        maxCnt = max(cnt, maxCnt);
    }

    cout << maxCnt << '\n';

    cnt = 0;
    unordered_set<int> ans;
    for (int i = 0; i < a.size(); i++) {
        if (a[i].first > 0) {
            cnt++;
            ans.insert(a[i].first);
        } else {
            cnt--;
            ans.erase(-a[i].first);
        }

        if (ans.size() == maxCnt) {
            for (int v : ans)
                cout << v << ' ';
            break;
        }
    }
}
