#include <iostream>
#include <algorithm>

using namespace std;

bool sieve[4000001];

void init() {
    fill(sieve, sieve + 4000001, true);
    for (int i = 2; i * i <= 4000001; i++)
        if (sieve[i])
            for (int j = 2; i * j <= 4000001; j++)
                sieve[i * j] = false;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, b, d;
    cin >> a >> b >> d;
    int ans = 0;

    init();

    for (int i = a; i <= b; i++) {
        if (!sieve[i])
            continue;

        int p = i;
        while (p) {
            if (p % 10 == d) {
                ans++;
                break;
            }
            p /= 10;
        }
    }

    cout << ans;
}
