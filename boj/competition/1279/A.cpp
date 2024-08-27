#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s[3];
    cin >> s[0] >> s[1] >> s[2];
    bool found[3];
    found[0] = found[1] = found[2] = false;

    for (string t : s) {
        if (t[0] == 'l')
            found[0] = true;
        else if (t[0] == 'k')
            found[1] = true;
        else if (t[0] == 'p')
            found[2] = true;
    }

    for (int i = 0; i < 3; i++) {
        if (!found[i]) {
            cout << "PONIX";
            return 0;
        }
    }
    cout << "GLOBAL";
}
