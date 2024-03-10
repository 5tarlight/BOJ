#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    char a[n][n];

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            a[i][j] = s[j];
        }
    }

    char ans[n][n];
    bool boom = false;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < n; j++) {
            if (s[j] == '.')
                ans[i][j] = '.';
            else {
                if (a[i][j] == '*') {
                    boom = true;
                    continue;
                }

                int cnt = 0;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        if (i + x >= 0 && i + x < n && j + y >= 0 && j + y < n) {
                            if (a[i + x][j + y] == '*') {
                                cnt++;
                            }
                        }
                    }
                }

                ans[i][j] = cnt + '0';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (boom && a[i][j] == '*') {
                cout << '*';
            } else {
                cout << ans[i][j];
            }
        }
        cout << '\n';
    }
}
