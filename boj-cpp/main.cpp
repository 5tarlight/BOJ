#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int yes[n + 2];
    yes[0] = 0;
    yes[1] = 1;
    for (int i = 2; i <= n + 1; i++) {
        int op, x, y;
        cin >> op >> x >> y;
        int cnt = yes[y] - yes[x - 1];
        int dist = y - x + 1;

        if (op == 1 && cnt == dist || op == 2 && cnt == 0) {
            yes[i] = yes[i - 1] + 1;
            cout << "Yes\n";
        } else {
            yes[i] = yes[i - 1];
            cout << "No\n";
        }
    }
}
