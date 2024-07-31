#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    double x, y;
    cin >> x >> y;
    double ans = x * 1000 / y;
    int n;
    cin >> n;
    while (n--) {
        double a, b;
        cin >> a >> b;
        double nxt = a * 1000 / b;
        if (nxt < ans)
            ans = nxt;
    }

    cout << ans;
}
