#include <iostream>
#include <algorithm>
using namespace std;

int dist(int a, int b) {
    return abs(a / 10 - b / 10) + abs(a % 10 - b % 10);
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long s;
    cin >> s;

    int loc[4], hitCnt = 0, m = 0;
    bool hit[4] = {};

    for (int i = 0; i < 4; i++) {
        do {
            s = s + s / 13 + 15;
            loc[i] = s % 100;
        } while (find(loc, loc + i, loc[i]) != loc + i);
    }

    while (hitCnt < 4) {
        int x;
        cin >> x;
        m++;

        for (int i = 0; i < 4; i++) {
            if (!hit[i] && loc[i] == x) {
                cout << "You hit a wumpus!\n";
                hit[i] = true;
                hitCnt++;
                break;
            }
        }

        int near = 100;
        for (int i = 0; i < 4; i++)
            if (!hit[i])
                near = min(near, dist(x, loc[i]));
        if (near == 100) break;
        cout << near << '\n';
    }

    cout << "Your score is " << m << " moves.\n";
}
