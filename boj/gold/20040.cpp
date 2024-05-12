#include <iostream>

using namespace std;

int parents[500001];

int find(int x) {
    if (x == parents[x])
        return x;
    else return parents[x] = find(parents[x]);
}

void merge(int a, int b) {
    int ap = find(a);
    int bp = find(b);
    if (ap == bp) return;

    parents[ap] = bp;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        parents[i] = i;


    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b)) {
            cout << i;
            return 0;
        }

        merge(a, b);
    }

    cout << 0;
}
