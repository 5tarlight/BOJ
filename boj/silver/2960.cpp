#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    bool filter[n + 1];
    fill(filter, filter + n + 1, true);
    int cnt = 0;

    for (int i = 2; i <= n; i++) {
        if (filter[i]) {
            for (int j = i; j <= n; j += i) {
                if (filter[j]) {
                    filter[j] = false;
                    cnt++;
                    if (cnt == k) {
                        cout << j;
                        return 0;
                    }
                }
            }
        }
    }
}
