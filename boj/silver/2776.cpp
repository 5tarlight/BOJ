#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    int v;
    int n, m;
    while (t--) {
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        cin >> m;

        while (m--) {
            cin >> v;
            int found = binary_search(a, a + n, v);
            if (found)
                cout << "1\n";
            else
                cout << "0\n";
        }
    }
}
