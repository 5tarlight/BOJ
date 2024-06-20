#include <iostream>

using namespace std;

int n;
int a[500001];
int tmp[500001];
long long ans = 0;

void merge(int l, int r) {
    int mid = (l + r) / 2;
    int i = l;
    int j = mid + 1;
    int k = l;
    int cnt = 0;

    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            tmp[k++] = a[i++];
            ans += cnt;
        } else {
            tmp[k++] = a[j++];
            cnt++;
        }
    }

    if (i > mid) {
        int s = j;
        while (s <= r) {
            tmp[k++] = a[s++];
            cnt++;
        }
    } else {
        int s = i;
        while (s <= mid) {
            tmp[k++] = a[s++];
            ans += cnt;
        }
    }

    for (int t = l; t <= r; t++)
        a[t] = tmp[t];
}

void msort(int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        msort(l, mid);
        msort(mid + 1, r);
        merge(l, r);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    msort(0, n - 1);
    cout << ans;
}
