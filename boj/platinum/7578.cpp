#include <iostream>

using namespace std;

int n;
int a[500001];
int b[1000001];
int tree[500001 * 4];

void update(int node, int start, int end, int index) {
    if (start > index || end < index)
        return;

    if (start == end) {
        tree[node] = 1;
        return;
    }

    int mid = (start + end) / 2;
    update(node * 2, start, mid, index);
    update(node * 2 + 1, mid + 1, end, index);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long sum(int node, int start, int end, int left, int right) {
    if (start > right || end < left)
        return 0;

    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        b[num] = i;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += sum(1, 0, n - 1, b[a[i]] + 1, n - 1);
        update(1, 0, n - 1, b[a[i]]);
    }

    cout << ans;
}
