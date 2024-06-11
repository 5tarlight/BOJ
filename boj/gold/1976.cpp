#include <iostream>

using namespace std;

int parents[200];

int find(int x) {
    if (parents[x] == x)
        return x;
    else
        return parents[x] = find(parents[x]);
}

void unite(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if (pa != pb)
        parents[pa] = pb;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        parents[i] = i;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            if (num == 1)
                unite(i, j);
        }
    }

    int a[m];
    bool ok = true;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < m - 1; i++)
        for (int j = i + 1; j < m; j++)
            if (find(a[i]) != find(a[j]))
                ok = false;

    if (ok)
        cout << "YES";
    else
        cout << "NO";
}
