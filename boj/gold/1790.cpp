#include <iostream>
#include <string>

using namespace std;

int main() {
    using ll = long long;
    ll n, k;
    cin >> n >> k;

    ll start = 0;
    ll digit = 1;
    ll end = 9;

    while (k > end * digit) {
        k -= digit * end;
        start += end;
        end *= 10;
        digit += 1;
    }

    ll ans = start + 1 + (k - 1) / digit;

    if (ans > n) {
        cout << -1 << endl;
    } else {
        string ansStr = to_string(ans);
        cout << ansStr[(k - 1) % digit] << endl;
    }

    return 0;
}
