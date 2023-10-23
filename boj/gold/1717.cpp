#include <iostream>
#include <algorithm>

using namespace std;

int n;
int parent[1'000'001];

int find(int x) {
    if (parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]), parent[x];
}

void uni(int x, int y) {
    int a = find(x);
    int b = find(y);

    parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q;
    cin >> n >> q;

    for (int i = 0; i <= n; i++)
        parent[i] = i;

    while (q--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 0)
            uni(a, b);
        else {
            if (find(a) == find(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}
