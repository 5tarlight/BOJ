#include <iostream>
#include <stack>

using namespace std;

int parent[200001];

int find(int x) {
    return parent[x] == -1 ? x : parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) parent[y] = x;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    int localparent[n + 1];
    fill(parent, parent + n + 1, -1);
    for (int i = 2; i <= n; i++) {
        cin >> localparent[i];
    }

    q += n - 1;
    int query[q][3];
    for (int i = 0; i < q; i++) {
        cin >> query[i][0] >> query[i][1];

        if (query[i][0] == 1) {
            cin >> query[i][2];
        }
    }

    stack<bool> ans;
    for (int i = q - 1; i >= 0; i--) {
        if (query[i][0] == 0)
            merge(query[i][1], localparent[query[i][1]]);
        else {
            if (find(query[i][1]) == find(query[i][2]))
                ans.push(true);
            else
                ans.push(false);
        }
    }

    while (!ans.empty()) {
        if (ans.top())
            cout << "YES\n";
        else
            cout << "NO\n";
        ans.pop();
    }
}
