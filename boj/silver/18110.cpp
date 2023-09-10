#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    vector<int> scores;
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        scores.push_back(s);
    }

    sort(scores.begin(), scores.end());

    double raw = n * 15.0 / 100;
    int offset = (int)round(raw);

    int sum = accumulate(scores.begin() + offset, scores.end() - offset, 0);
    double rawAvg = (double)sum / (n - 2 * offset);

    cout << round(rawAvg);
}
