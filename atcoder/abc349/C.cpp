#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;

    int prev = -1;
    for (int i = 0; i < 3; i++) {
        char ch = t[i] + ('a' - 'A');

        if (ch == 'x' && i == 2) {
            cout << "Yes";
            return 0;
        }

        for (int j = prev + 1; j < s.size(); j++) {
            if (s[j] == ch) {
                prev = j;
                break;
            }
            if (j == s.size() - 1) {
                cout << "No";
                return 0;
            }
        }
    }

    cout << "Yes";
}
