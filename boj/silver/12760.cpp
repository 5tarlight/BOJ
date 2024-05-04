#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int card[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> card[i][j];
        sort(card[i], card[i] + m, greater<>());
    }

    int score[n];
    fill(score, score + n, 0);

    for (int i = 0; i < m; i++) {
        int max = 0;
        for (int j = 0; j < n; j++) {
            if (card[j][i] > max)
                max = card[j][i];
        }
        for (int j = 0; j < n; j++) {
            if (card[j][i] == max)
                score[j]++;
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        if (score[i] > max)
            max = score[i];
    }

    for (int i = 0; i < n; i++) {
        if (score[i] == max)
            cout << i + 1 << ' ';
    }
}
