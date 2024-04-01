#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int sum = 0;
        int a[n];
        int max = 0;
        int maxCnt = 0;
        int maxi = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];

            if (a[i] > max) {
                max = a[i];
                maxCnt = 1;
                maxi = i + 1;
            } else if (a[i] == max) {
                maxCnt++;
            }
        }

        if (maxCnt > 1) {
            cout << "no winner\n";
        } else if (max > sum / 2) {
            cout << "majority winner " << maxi << '\n';
        } else {
            cout << "minority winner " << maxi << '\n';
        }
    }
}
