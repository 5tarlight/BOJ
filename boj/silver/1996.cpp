#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int map[n][n];

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            char ch = s[j];
            if (ch == '.')
                map[i][j] = -1;
            else
                map[i][j] = ch - '0';

        }
    }

    char result[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] != -1) {
                result[i][j] = '*';
                continue;
            }

            int cnt = 0;
            if (i > 0) {
                if (j > 0 && map[i - 1][j - 1] != -1)
                    cnt += map[i - 1][j - 1];
                if (map[i - 1][j] != -1)
                    cnt += map[i - 1][j];
                if (j < n - 1 && map[i - 1][j + 1] != -1)
                    cnt += map[i - 1][j + 1];
            }
            if (j > 0 && map[i][j - 1] != -1)
                cnt += map[i][j - 1];
            if (j < n - 1 && map[i][j + 1] != -1)
                cnt += map[i][j + 1];
            if (i < n - 1) {
                if (j > 0 && map[i + 1][j - 1] != -1)
                    cnt += map[i + 1][j - 1];
                if (map[i + 1][j] != -1)
                    cnt += map[i + 1][j];
                if (j < n - 1 && map[i + 1][j + 1] != -1)
                    cnt += map[i + 1][j + 1];
            }

            if (cnt > 9)
                result[i][j] = 'M';
            else
                result[i][j] = (char)(cnt + '0');
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j];
        }
        cout << '\n';
    }
}
