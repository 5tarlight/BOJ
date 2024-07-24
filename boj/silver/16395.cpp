#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    __int128 f[31];
    f[0] = 1;
    for (int i = 1; i <= 30; i++)
        f[i] = f[i - 1] * i;

    int n, k;
    cin >> n >> k;
    n--; k--;

    cout << (long long)(f[n] / f[k] / f[n - k]);
}
