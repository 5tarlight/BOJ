#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    vector<int> fibo;
    fibo.push_back(0);
    fibo.push_back(1);
    for (int i = 2; i <= 45; i++) {
        fibo.push_back(fibo[i - 1] + fibo[i - 2]);
        if (fibo[i] > 1000000000) {
            break;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        vector<int> ans;
        int n;
        cin >> n;
        int sum = 0;

        while (sum != n) {
            auto it = lower_bound(fibo.begin(), fibo.end(), n - sum);
            if (*it > n - sum) {
                it--;
            }
            sum += *it;
            ans.push_back(*it);
        }

        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}
