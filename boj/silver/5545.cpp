#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    int a, b, dough;
    cin >> n >> a >> b >> dough;
    int c[n];

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    sort(c, c + n, greater<int>());

    int cal = dough;
    int price = a;
    int ans = cal / price;
    for (int i = 0; i < n; i++) {
        cal += c[i];
        price += b;
        ans = max(ans, cal / price);
    }

    cout << ans;
}
