#include "bits/stdc++.h"

using namespace std;

int n;
int a[1025];
vector<int> ans[10];

void sol(int d, int l, int r) {
    if (d == n - 1) {
        ans[d].push_back(a[l]);
        return;
    }

    int mid = (l + r) / 2;
    sol(d + 1, l, mid);
    sol(d + 1, mid + 1, r);
    ans[d].push_back(a[mid]);
}

int main() {
    cin >> n;
    for (int i = 0; i < (1 << n) - 1; i++)
        cin >> a[i];

    sol(0, 0, (1 << n) - 1);

    for (int i = 0; i < n; i++) {
        for (int v : ans[i]) cout << v << ' ';
        cout << '\n';
    }
}
