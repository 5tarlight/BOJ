#include <iostream>

using namespace std;

bool cover[101][101];

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                cover[a + i][b + j] = true;
    }

    int cnt = 0;
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            if (cover[i][j])
                cnt++;
    cout << cnt;
}
