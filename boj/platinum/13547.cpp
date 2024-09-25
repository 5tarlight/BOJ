#include "bits/stdc++.h"
#define MAX 1000001

using namespace std;

struct query {
    int l, r, idx;
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, s;
    int a[MAX];
    vector<query> q;
    int val = 0, l, r;
    vector<int> ans, cnt;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> m;
    for (int k = 0; k < m; k++) {
        int i, j;
        cin >> i >> j;
        q.push_back({ i - 1, j - 1, k });
    }

    auto comp = [&](query a, query b) {
        if (a.l / s != b.l / s) {
            return a.l / s < b.l / s;
        }
        return a.r < b.r;
    };

    s = sqrt(n);
    sort(q.begin(), q.end(), comp);
    ans.resize(m);
    cnt.resize(MAX);

    l = q[0].l;
    r = q[0].r;
    for (int i = l; i <= r; i++) {
        if (cnt[a[i]] == 0) {
            val++;
        }
        cnt[a[i]]++;
    }
    ans[q[0].idx] = val;

    for (int i = 1; i < m; i++) {
        int nl = q[i].l;
        int nr = q[i].r;

        while (nl < l) {
            l--;
            if (cnt[a[l]] == 0) {
                val++;
            }
            cnt[a[l]]++;
        }

        while (nl > l) {
            cnt[a[l]]--;
            if (cnt[a[l]] == 0) {
                val--;
            }
            l++;
        }

        while (nr > r) {
            r++;
            if (cnt[a[r]] == 0) {
                val++;
            }
            cnt[a[r]]++;
        }

        while (nr < r) {
            cnt[a[r]]--;
            if (cnt[a[r]] == 0) {
                val--;
            }
            r--;
        }

        ans[q[i].idx] = val;
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}
