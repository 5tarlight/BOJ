#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int p1, p2, p3, p4, p5;
    cin >> p1 >> p2 >> p3 >> p4 >> p5;
    vector<int> q[5];

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        q[a - 1].push_back(b);
    }

    for (int i = 0; i < 5; i++) {
        sort(q[i].begin(), q[i].end());
    }

    int time = 0;
    int prev;
    for (int i = 0; i < p1; i++) {
        if (i != 0)
            time += q[0][i] - prev;
        time += q[0][i];
        prev = q[0][i];
    }
    time += 60;
    for (int i = 0; i < p2; i++) {
        if (i != 0)
            time += q[1][i] - prev;
        time += q[1][i];
        prev = q[1][i];
    }
    time += 60;
    for (int i = 0; i < p3; i++) {
        if (i != 0)
            time += q[2][i] - prev;
        time += q[2][i];
        prev = q[2][i];
    }
    time += 60;
    for (int i = 0; i < p4; i++) {
        if (i != 0)
            time += q[3][i] - prev;
        time += q[3][i];
        prev = q[3][i];
    }
    time += 60;
    for (int i = 0; i < p5; i++) {
        if (i != 0)
            time += q[4][i] - prev;
        time += q[4][i];
        prev = q[4][i];
    }

    cout << time;
}
