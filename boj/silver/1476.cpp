#include <iostream>

using namespace std;

int main() {
    int e, s, m;
    cin >> e >> s >> m;
    int ans = (6916 * e + 4845 * s + 4200 * m) % 7980;
    if (ans == 0)
        ans = 7980;
    cout << ans;
}
