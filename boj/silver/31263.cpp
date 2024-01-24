#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    int i = 0;

    while (i < n) {
        if (s[i] == '0') {
            i--;
            continue;
        }

        if (s[i] < '6') {
            i += 3;
        } else if (s[i] == '6') {
            if (s[i + 1] < '4')
                i += 3;
            else if (s[i + 1] > '4')
                i += 2;
            else {
                if (s[i + 2] <= '1')
                    i += 3;
                else
                    i += 2;
            }
        } else
            i += 2;

        cnt++;
    }

    cout << cnt;
}
