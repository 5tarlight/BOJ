#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    stack<int> s;
    stack<int> c;
    int cnt = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;

        if (s.empty() || s.top() < l) {
            if (!s.empty() && s.top() + 1 != l) {
                cout << -1;
                return 0;
            } else if (s.empty() && l != 1) {
                cout << -1;
                return 0;
            }
            ans.push_back(1);
            s.push(l);
            c.push(cnt);
            cnt = 1;
        } else if (s.top() == l) {
            ans.push_back(++cnt);
        } else {
            int gap = s.top() - l;
            while (gap--) {
                cnt = c.top();
                c.pop();
                s.pop();
            }

            ans.push_back(++cnt);
        }
    }

    for (int v : ans)
        cout << v << ' ';
}
