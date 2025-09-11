#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int n, k;
vector<int> arr, tmp;
int cnt = 0;
int ans = -1;

void msort(int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;

        msort(l, mid);
        msort(mid + 1, r);

        int i = l, j = mid + 1, t = 0;

        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) tmp[t++] = arr[i++];
            else tmp[t++] = arr[j++];
        }

        while (i <= mid) tmp[t++] = arr[i++];
        while (j <= r) tmp[t++] = arr[j++];

        i = l; t = 0;
        while (i <= r) {
            arr[i] = tmp[t++];
            cnt++;
            if (cnt == k) ans = arr[i];
            i++;
        }
    }
}

int main() {
    fio();

    cin >> n >> k;
    arr.resize(n);
    tmp.resize(n);

    for (int i = 0; i < n; i++) cin >> arr[i];
    msort(0, n - 1);

    cout << ans;
}
