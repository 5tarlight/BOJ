#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int tk = 1; tk <= t; tk++) {
        int n, c, l;
        cin >> n >> c >> l;

        int drunkCnt[l + 1];
        int normalCnt[l + 1];
        fill(drunkCnt, drunkCnt + l + 1, 0);
        fill(normalCnt, normalCnt + l + 1, 0);

        for (int i = 0; i < n; i++) {
            int loc;
            char status;
            cin >> loc >> status;

            if (status == 'I')
                drunkCnt[loc]++;
            else
                normalCnt[loc]++;
        }

        pair<int, int> cars[c];
        for (int i = 0; i < c; i++) {
            int loc, cap;
            cin >> loc >> cap;
            cars[i] = {loc, cap};
        }
        sort(cars, cars + c, greater<>());

        for (auto &car : cars) {
            int to = car.first;
            int cap = car.second;

            if (normalCnt[to] > 0) {
                normalCnt[to]--;
                cap--;

                if (drunkCnt[to] >= cap)
                    drunkCnt[to] -= cap;
                else {
                    cap -= drunkCnt[to];
                    drunkCnt[to] = 0;
                    normalCnt[to] -= cap;
                }
            }
        }

        int ans = 0;
        for (int v : normalCnt)
            ans += max(0, v);
        for (int v : drunkCnt)
            ans += max(0, v);

        cout << "Data Set " << tk << ":\n";
        cout << ans << "\n";
    }

}
