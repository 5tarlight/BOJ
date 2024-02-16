#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)
            return 0;

        int sang[n];
        for (int i = 0; i < n; i++)
            cin >> sang[i];

        int cnt = 0;
        while (m--) {
            int num;
            cin >> num;

            if (binary_search(sang, sang + n, num))
                cnt++;
        }

        cout << cnt << '\n';
    }
}
