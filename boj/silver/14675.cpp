#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int child[n + 1];
    fill(child, child + n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        child[a]++;
        child[b]++;
    }

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        if (a == 2)
            cout << "yes\n";
        else {
            if (child[b] == 1)
                cout << "no\n";
            else
                cout << "yes\n";
        }
    }
}
