#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int n, k;
string s[16];
ll dp[1 << 15][100];
int cache[51];
int strCache[15];

int mod(string &s, int div) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans *= 10;
        ans += s[i] - '0';
        ans %= div;
    }

    return ans;
}

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    cin >> k;

    dp[0][0] = 1;
    cache[0] = 1 % k;
    for (int i = 1; i <= 50; i++)
        cache[i] = (cache[i - 1] * 10) % k;
    for (int i = 0; i < n; i++)
        strCache[i] = mod(s[i], k);

    for (int cur = 0; cur < (1 << n); cur++) {
        for (int i = 0; i < n; i++) {
            if ((cur & (1 << i)) == 0) {
                int nxt = cur | (1 << i);
                for (int j = 0; j < k; j++) {
                    int nk = ((j * cache[s[i].size()]) % k + strCache[i]) % k;
                    dp[nxt][nk] += dp[cur][j];
                }
            }
        }
    }

    ll a = 1, b = dp[(1 << n) - 1][0];
    for (int i = 1; i <= n; i++)
        a *= i;
    ll g = gcd(a, b);

    cout << b / g << '/' << a / g;
}
