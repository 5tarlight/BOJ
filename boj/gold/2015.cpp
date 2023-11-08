#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n, k;
    cin >> n >> k;
    long long sum[n + 1];
    sum[0] = 0;
    map<long long, long long> m;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        sum[i] = num + sum[i - 1];
    }

    long long cnt = 0;
    for (long long i = 1; i <= n; i++) {
        if (sum[i] == k)
            cnt++;
        cnt += m[sum[i] - k];
        m[sum[i]]++;
    }

    cout << cnt;
}
