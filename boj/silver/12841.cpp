#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    long long dist[n], a[n], b[n];
    for (int i = 0; i < n; i++)
        cin >> dist[i];
    a[0] = b[0] = 0;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i < n; i++) {
        cin >> b[i];
        b[i] += b[i - 1];
    }

    long long ans = 1e18;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        long long nxt = a[i] + dist[i] + b[n - 1] - b[i];
        if (nxt < ans) {
            ans = nxt;
            idx = i + 1;
        }
    }

    cout << idx << ' ' << ans;
}
