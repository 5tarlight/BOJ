#include "bits/stdc++.h"
using namespace std;

#define SZ 100001

struct Q {
    int i, s, e;
};

int a[SZ], c[SZ], rn, ans[SZ], ret, input[SZ];
Q q[SZ];
vector<int> idx[2 * SZ];

bool cmp(Q& x, Q& y) {
    if (x.s / rn == y.s / rn) {
        if (x.e == y.e) return x.s < y.s;
        return x.e < y.e;
    }
    return x.s / rn < y.s / rn;
}

void radd(int x) {
    int l, r;
    if (idx[a[x]].size() >= 2) {
        l = idx[a[x]].front();
        r = idx[a[x]].back();
        c[r - l]--;
    }
    idx[a[x]].push_back(x);
    if (idx[a[x]].size() >= 2) {
        l = idx[a[x]].front();
        r = idx[a[x]].back();
        c[r - l]++;
        ret = max(ret, r - l);
    }
}

void rdis(int x) {
    int l, r;
    if (idx[a[x]].size() >= 2) {
        l = idx[a[x]].front();
        r = idx[a[x]].back();
        c[r - l]--;
    }
    idx[a[x]].pop_back();
    if (idx[a[x]].size() >= 2) {
        l = idx[a[x]].front();
        r = idx[a[x]].back();
        c[r - l]++;
        ret = max(ret, r - l);
    }
}

void ladd(int x) {
    int l, r;
    if (idx[a[x]].size() >= 2) {
        l = idx[a[x]].front();
        r = idx[a[x]].back();
        c[r - l]--;
    }
    idx[a[x]].insert(idx[a[x]].begin(), x);
    if (idx[a[x]].size() >= 2) {
        l = idx[a[x]].front();
        r = idx[a[x]].back();
        c[r - l]++;
        ret = max(ret, r - l);
    }
}

void ldis(int x) {
    int l, r;
    if (idx[a[x]].size() >= 2) {
        l = idx[a[x]].front();
        r = idx[a[x]].back();
        c[r - l]--;
    }
    idx[a[x]].erase(idx[a[x]].begin());
    if (idx[a[x]].size() >= 2) {
        l = idx[a[x]].front();
        r = idx[a[x]].back();
        c[r - l]++;
        ret = max(ret, r - l);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n;
    rn = sqrt(n + 1);
    a[1] = n;

    for (int i = 1; i <= n; i++) {
        cin >> input[i];
        a[i + 1] = a[i] + input[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> q[i].s >> q[i].e;
        q[i].i = i;
        q[i].e++;
    }

    sort(q, q + m, cmp);

    int s = q[0].s, e = q[0].e;
    for (int i = s; i <= e; i++) radd(i);
    ans[q[0].i] = ret;

    c[0] = n + 2;
    for (int i = 1; i < m; i++) {
        while (s > q[i].s) ladd(--s);
        while (e < q[i].e) radd(++e);
        while (s < q[i].s) ldis(s++);
        while (e > q[i].e) rdis(e--);
        while (c[ret] == 0) ret--;
        ans[q[i].i] = ret;
    }

    for (int i = 0; i < m; i++)
        cout << ans[i] << '\n';
}
