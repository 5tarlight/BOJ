#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, C, W;
    cin >> N >> C >> W;
    vector<int> trees(N);

    for (int i = 0; i < N; i++) {
        cin >> trees[i];
    }

    long long maxProfit = 0;

    for (int L = 1; L <= *max_element(trees.begin(), trees.end()); L++) {
        long long currentProfit = 0;

        for (int i = 0; i < N; i++) {
            long long length = trees[i];
            long long pieces = length / L;
            long long cuts = (length % L == 0) ? pieces - 1 : pieces;

            long long profit = pieces * L * W - cuts * C;
            if (profit > 0)
                currentProfit += profit;
        }

        maxProfit = max(maxProfit, currentProfit);
    }

    cout << maxProfit << endl;
    return 0;
}
