#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    const long long thres = 5e6;
    while (t--) {
        vector<int> a;
        while (true) {
            int x;
            cin >> x;
            if (x == 0) break;
            a.push_back(x);
        }
        sort(a.begin(), a.end(), greater<>());

        long long tmp = 0;
        for (int i = 0; i < a.size(); i++) {
            long long v = 2;
            for (int j = 0; j <= i; j++)
                v *= a[i];
            tmp += v;
        }

        if (tmp > thres)
            cout << "Too expensive\n";
        else
            cout << tmp << '\n';
    }
}
