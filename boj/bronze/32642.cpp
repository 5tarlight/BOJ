#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    long long ans = 0;
    int fury = 0;

    int n; cin >> n;
    while (n--) {
        int x;
        cin >> x;
        if (x)
            fury++;
        else
            fury--;
        ans += fury;
    }

    cout << ans;
}
