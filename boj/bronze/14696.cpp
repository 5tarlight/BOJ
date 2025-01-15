#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        int aa[4] = { 0, };
        while (a--) {
            int x;
            cin >> x;
            aa[x - 1]++;
        }

        int b;
        cin >> b;
        int bb[4] = { 0, };
        while (b--) {
            int x;
            cin >> x;
            bb[x - 1]++;
        }

        bool ok = false;
        for (int i = 3; i >= 0; i--) {
            if (aa[i] != bb[i]) {
                ok = true;

                if (aa[i] > bb[i]) cout << "A\n";
                else cout << "B\n";

                break;
            }
        }

        if (!ok) cout << "D\n";
    }
}
