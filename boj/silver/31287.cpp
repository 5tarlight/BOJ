#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    if (k > (n / 2))
        k = n / 2;

    int x = 0, y = 0;
    while (k--) {
        for (long long i = 0; i < n; i++) {
            char op = s[i];
            if (op == 'U')
                y++;
            else if (op == 'R')
                x++;
            else if (op == 'L')
                x--;
            else if (op == 'D')
                y--;

            if (x == 0 && y == 0) {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";
}
