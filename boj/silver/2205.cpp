#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int target = 1;
    while (target <= n) target <<= 1;

    vector<int> ans;
    vector<bool> visited(n + 1, false);

    for (int i = n; i >= 1; i--) {
        for (int j = target; j >= 1; j >>= 1) {
            if (!visited[j - i] && j - i <= n) {
                ans.push_back(j - i);
                visited[j - i] = true;
                break;
            }
        }
    }

    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << '\n';
}
