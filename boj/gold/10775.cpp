#include <iostream>
#include <algorithm>

using namespace std;

int p[100001];

int find(int x) {
    if (x == p[x]) return x;
    else return p[x] = find(p[x]);
}

void uni(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if (pa > pb)
        swap(pa, pb);
    p[pb] = pa;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        p[i] = i;

    int ans = 0;
    while (m--) {
        int a;
        cin >> a;
        int pa = find(a);

        if (pa == 0)
            break;

        uni(pa, pa - 1);
        ans++;
    }

    cout << ans;
}
