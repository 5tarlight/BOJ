#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, t;
    cin >> n >> t;
    vector<int> times;
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int i = 0; i < c; i++)
            times.push_back(a + i * b);
    }
    sort(times.begin(), times.end());

    int idx = lower_bound(times.begin(), times.end(), t) - times.begin();

    if (idx == times.size())
        cout << -1;
    else
        cout << times[idx] - t;
}
