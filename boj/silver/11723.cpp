#include <iostream>
#include <cstring>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int s[21];
    memset(s, 0, sizeof(s));
    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        string str;
        int x;
        cin >> str;

        if (str == "add") {
            cin >> x;
            s[x] = 1;
        } else if (str == "remove") {
            cin >> x;
            s[x] = 0;
        } else if (str == "check") {
            cin >> x;
            cout << s[x] << '\n';
        } else if (str == "toggle") {
            cin >> x;
            s[x] = s[x] == 0 ? 1 : 0;
        } else if (str == "all") {
            for (int j = 1; j <= 20; j++)
                s[j] = 1;
        } else {
            memset(s, 0, sizeof(s));
        }
    }
}
