#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int parents[51];

int findp(int x) {
    if (parents[x] != x)
        return parents[x] = findp(parents[x]);
    return x;
}

void mergep(int a, int b) {
    int x = findp(parents[a]);
    int y = findp(parents[b]);

    if (x != y) {
        if (x < y)
            parents[y] = x;
        else
            parents[x] = y;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i <= n; i++) {
        parents[i] = i;
    }

    int l;
    cin >> l;
    while (l--) {
        int p;
        cin >> p;
        parents[p] = 0;
    }

    vector<int> party[m];
    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;

        int first;
        cin >> first;
        party[i].push_back(first);
        c--;

        while (c--) {
            int p;
            cin >> p;
            party[i].push_back(p);
            mergep(first, p);
        }
    }

    int ans = m;
    for (int i = 0; i < m; i++) {
        for (int &p : party[i]) {
            if (findp(parents[p]) == 0) {
                ans--;
                break;
            }
        }
    }

    cout << ans;
}
