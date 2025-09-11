#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int n;
int a[20][20];
int ans = 1e9;
int aa[10], bb[10];
int ai = 0, bi = 0;

void go(int x) {
    if (x == n) {
        int asum = 0;
        for (int i = 0; i < n / 2; i++)
            for (int j = 0; j < n / 2; j++)
                asum += a[aa[i]][aa[j]];

        int bsum = 0;
        for (int i = 0; i < n / 2; i++)
            for (int j = 0; j < n / 2; j++)
                bsum += a[bb[i]][bb[j]];

        ans = min(ans, abs(asum - bsum));
        return;
    }

    if (ai < n / 2) {
        aa[ai++] = x;
        go(x + 1);
        ai--;
    }
    if (bi < n / 2) {
        bb[bi++] = x;
        go(x + 1);
        bi--;
    }
}

int main() {
    fio();

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    go(0);
    cout << ans;
}
