#include <iostream>
#include <string>

using namespace std;

bool isLower(char ch) {
    return ch >= 'a' && ch <= 'z';
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    bool isCpp = true;
    bool isJava = true;

    for (int i = 0; i < s.size(); i++) {
        if (i == 0 && !isLower(s[i])) {
            isCpp = false;
            isJava = false;
        }

        if (s[i] == '_') {
            isJava = false;

            if (i == 0 || i == s.size() - 1 || s[i + 1] == '_')
                isCpp = false;
        } else if (!isLower(s[i])) {
            isCpp = false;
        }
    }

    if (!isCpp && !isJava) {
        cout << "Error!";
    } else if (isCpp) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '_') {
                cout << (char)(s[i + 1] - 32);
                i++;
            } else {
                cout << s[i];
            }
        }
    } else {
        for (int i = 0; i < s.size(); i++) {
            if (isLower(s[i])) {
                cout << s[i];
            } else {
                cout << "_" << (char)(s[i] + 32);
            }
        }
    }
}
