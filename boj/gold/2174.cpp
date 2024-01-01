#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    int n, m;
    cin >> n >> m;

    pair<int, pair<int, char>> bots[n];

    for (int i = 0; i < n; i++) {
        int x, y;
        char f;
        cin >> x >> y >> f;
        bots[i] = make_pair(x, make_pair(y, f));
    }

    bool done = false;
    while (m--) {
        int bot;
        char op;
        int repeat;
        cin >> bot >> op >> repeat;

        if (done)
            continue;

        while (repeat--) {
            if (done)
                break;

            if (op == 'L') {
                if (bots[bot - 1].second.second == 'N')
                    bots[bot - 1].second.second = 'W';
                else if (bots[bot - 1].second.second == 'W')
                    bots[bot - 1].second.second = 'S';
                else if (bots[bot - 1].second.second == 'S')
                    bots[bot - 1].second.second = 'E';
                else
                    bots[bot - 1].second.second = 'N';
            } else if (op == 'R') {
                if (bots[bot - 1].second.second == 'N')
                    bots[bot - 1].second.second = 'E';
                else if (bots[bot - 1].second.second == 'E')
                    bots[bot - 1].second.second = 'S';
                else if (bots[bot - 1].second.second == 'S')
                    bots[bot - 1].second.second = 'W';
                else
                    bots[bot - 1].second.second = 'N';
            } else {
                if (bots[bot - 1].second.second == 'N')
                    bots[bot - 1].second.first++;
                else if (bots[bot - 1].second.second == 'W')
                    bots[bot - 1].first--;
                else if (bots[bot - 1].second.second == 'S')
                    bots[bot - 1].second.first--;
                else
                    bots[bot - 1].first++;

                if (bots[bot - 1].first <= 0 || bots[bot - 1].first > a || bots[bot - 1].second.first <= 0 || bots[bot - 1].second.first > b) {
                    cout << "Robot " << bot << " crashes into the wall";
                    done = true;
                    break;
                }

                for (int i = 0; i < n; i++) {
                    if (i + 1 == bot || done)
                        continue;

                    if (bots[bot - 1].first == bots[i].first && bots[bot - 1].second.first == bots[i].second.first) {
                        done = true;
                        cout << "Robot " << bot << " crashes into robot " << (i + 1);
                        break;
                    }
                }
            }
        }
    }

    if (!done)
        cout << "OK";
}
