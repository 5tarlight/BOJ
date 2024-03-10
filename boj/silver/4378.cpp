#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    char keys[][13] = {
            {'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '='},
            {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\'},
            {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\''},
            {'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/'}
    };
    string s;


    while (getline(cin, s)) {
        for (char ch : s) {
            if (ch == ' ') {
                cout << ' ';
                continue;
            }

            bool found = false;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 13; j++) {
                    if (keys[i][j] == ch) {
                        cout << keys[i][j - 1];
                        found = true;
                        break;
                    }
                }
                if (found)
                    break;
            }
        }
        cout << '\n';
    }
}
