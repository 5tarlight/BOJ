#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int pages[m];
    for (int i = 0; i < m; i++)
        cin >> pages[i];
    sort(pages, pages + m);

    vector<int> target;
    int prev = 0;
    for (int i = 0; i < m; i++) {
        if (pages[i] - 1 > prev)
            for (int j = prev + 1; j < pages[i]; j++)
                target.push_back(j);
        prev = pages[i];
    }
    for (int i = prev + 1; i <= n; i++)
        target.push_back(i);

    int ans = 0;
    int near = 0;
    for (int i = 0; i < target.size(); i++) {
        if (near == 0) {
            near = 1;
            continue;
        }

        if (target[i] - target[i - 1] > 3) {
            ans += 2 * near + 5;
            near = 1;
        } else {
            near += target[i] - target[i - 1];
        }
    }

    if (near > 0)
        ans += 2 * near + 5;

    cout << ans;
}
