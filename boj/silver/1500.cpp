#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int s, k;
    cin >> s >> k;
    long long a[k];
    long long sum = 0;
    for (int i = 0; i < k; i++) {
        a[i] = s / k;
        sum += a[i];
    }

    long long diff = s - sum;
    long long ans = 1;
    for (int i = 0; i < k; i++) {
        if (i < diff)
            ans *= (a[i] + 1);
        else
            ans *= a[i];
    }

    cout << ans;
}
