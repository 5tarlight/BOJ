#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    bool sieve[100001];
    int cnt[100001];
    fill(sieve, sieve + 100001, true);
    fill(cnt, cnt + 100001, 0);

    sieve[0] = sieve[1] = false;
    for (int i = 2; i <= 100000; i++) {
        if (sieve[i]) {
            for (int j = i * 2; j <= 100000; j += i) {
                sieve[j] = false;

                int cur = j;
                while (cur % i == 0) {
                    cnt[j]++;
                    cur /= i;
                }
            }
        }
    }

    int ans = 0;
    for (int i = a; i <= b; i++)
        if (sieve[cnt[i]])
            ans++;

    cout << ans;
}
