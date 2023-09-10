#include <iostream>

using namespace std;

int check(int x1, int y1, int x2, int y2) {
    if (x1 > x2 && y1 > y2)
        return 1;
    else if (x1 < x2 && y1 < y2)
        return 2;
    else
        return 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int n;
    cin >> n;
    int x[n], y[n];
    int score[n];

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        score[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int temp = 0;

        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            int ch = check(x[i], y[i], x[j], y[j]);
            if (ch == 2) {
                temp++;
            }
        }
        score[i] = temp + 1;
    }

    for (int r : score) {
        cout << r << " ";
    }
}
