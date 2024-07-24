#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int ans[10] = { 0, };

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        int cnt = 0;
        int idx = 0;

        while (cnt != num) {
            if (ans[idx] == 0)
                cnt++;
            idx++;
        }

        while (ans[idx] != 0)
            idx++;
        ans[idx] = i + 1;
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
}
