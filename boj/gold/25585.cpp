#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int abs(int x) {
    if (x < 0)
        return -x;
    else return x;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    pair<int, int> initPos;
    vector<pair<int, int>> target;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            if (num == 1) {
                target.push_back({ i, j });
            } else if (num == 2) {
                initPos = { i, j };
            }
        }
    }

    int startOdd = (initPos.first + initPos.second) % 2;
    for (auto p : target) {
        if ((p.first + p.second) % 2 != startOdd) {
            cout << "Shorei";
            return 0;
        }
    }

    sort(target.begin(), target.end());

    int ans = 1e9;
    do {
        auto prev = initPos;
        int time = 0;
        for (auto nxt : target) {
            int dist = max(abs(nxt.first - prev.first), abs(nxt.second - prev.second));
            time += dist;
            prev = nxt;
        }

        ans = min(ans, time);
    } while (next_permutation(target.begin(), target.end()));

    cout << "Undertaker\n";
    cout << ans;
}
