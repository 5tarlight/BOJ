#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    int order[k];
    int tab[n];
    for (int i = 0; i < k; i++)
        cin >> order[i];
    for (int i = 0; i < n; i++)
        tab[i] = 0;

    int ans = 0;
    for (int i = 0; i < k; i++) {
        bool already = false;
        for (int j = 0; j < n; j++) {
            if (order[i] == tab[j]) {
                already = true;
                break;
            }
        }

        if (already) continue;

        for (int j = 0; j < n; j++) {
            if (tab[j] == 0) {
                tab[j] = order[i];
                already = true;
                break;
            }
        }

        if (already) continue;

        int tabPos = -1;
        int idx = -1;
        for (int j = 0; j < n; j++) {
            int tmp = 0;
            for (int t = i + 1; t < k; t++) {
                if (tab[j] == order[t]) break;
                tmp++;
            }

            if (tmp > idx) {
                tabPos = j;
                idx = tmp;
            }
        }

        tab[tabPos] = order[i];
        ans++;
    }

    cout << ans;
}
