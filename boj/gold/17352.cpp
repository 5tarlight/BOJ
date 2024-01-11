#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int parents[300'001];

int find(int k) {
    if (parents[k] == k)
        return k;
    else
        return parents[k] = find(parents[k]);
}

void uni(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if (pa < pb)
        parents[pb] = pa;
    else
        parents[pa] = pb;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
        parents[i] = i;

    for (int i = 0; i < n - 2; i++) {
        int a, b;
        cin >> a >> b;
        uni(a, b);
    }

    int target = find(1);
    for (int i = 2; i <= n; i++) {
        int temp = find(i);
        if (target != temp) {
            cout << target << ' ' << temp;
            return 0;
        }
    }
}
