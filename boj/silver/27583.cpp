#include <iostream>
#include <algorithm>

using namespace std;

int abs(int x) {
    if (x < 0) return -x;
    else return x;
}

int dist(int a, int b) {
    int x1 = a / 10;
    int x2 = b / 10;
    int y1 = a % 10;
    int y2 = b % 10;

    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long s;
    cin >> s;

    int loc[4];
    for (int i = 0; i < 4; i++) {
        bool found = false;
        do {
            found = false;
            s = s + s / 13 + 15;
            int target = s % 100;
            for (int j = 0; j < i; j++)
                if (loc[j] == target)
                    found = true;
            loc[i] = target;
        } while (found);
    }

    bool hit[4] = { false, };

    int m = 0;
    int hitCnt = 0;
    while (true) {
        int x;
        cin >> x;
        m++;

        for (int i = 0; i < 4; i++) {
            if (hit[i]) continue;
            if (loc[i] == x) {
                cout << "You hit a wumpus!\n";
                hit[i] = true;
                hitCnt++;

                if (hitCnt == 4) {
                    cout << "Your score is " << m << " moves.";
                    return 0;
                }
                break;
            }
        }

        int near = 1e9;
        for (int i = 0; i < 4; i++) {
            if (hit[i]) continue;
            near = min(near, dist(x, loc[i]));
        }

        cout << near << '\n';
    }
}
