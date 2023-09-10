#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, b;
    cin >> n >> m >> b;
    int map[500][500];
    int minTime = 2147483647;
    int maxHeight = 256;


    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    for (int h = 0; h <= 256; h++) {
        int place = 0;
        int broke = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int gap = map[i][j] - h;

                if (gap > 0)
                    broke += gap;
                else if (gap < 0)
                    place -= gap;
            }
        }

        if (broke + b >= place) {
            int time = 2*broke + place;

            if (minTime >= time) {
                minTime = time;
                maxHeight = h;
            }
        }
    }

    cout << minTime << " " << maxHeight;
}
