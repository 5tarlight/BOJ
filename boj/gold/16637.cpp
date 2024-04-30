#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string s;
long long ans = -(1L << 31);
int n;

long long calc(long long a, long long b, char op) {
    long long res;
    if (op == '+') {
        res = a + b;
    } else if (op == '-') {
        res = a - b;
    } else {
        res = a * b;
    }

    return res;
}

void dfs(int idx, long long cur) {
    if (idx > n - 1) {
        ans = max(ans, cur);
        return;
    }

    char op = idx == 0 ? '+' : s[idx - 1];

    if (idx + 2 < n) {
        long long value = calc(s[idx] - '0', s[idx + 2] - '0', s[idx + 1]);
        dfs(idx + 4, calc(cur, value, op));
    }
    dfs(idx + 2, calc(cur, s[idx] - '0', op));
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> s;
    dfs(0, 0);
    cout << ans;
}
