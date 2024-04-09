#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    getline(cin, s);
    if (s[0] != '"' || s[s.size() - 1] != '"') {
        cout << "CE";
        return 0;
    }

    bool isBlank = true;
    for (int i = 1; i < s.size() - 1; i++)
        if (s[i] != ' ') {
            isBlank = false;
            break;
        }

    if (isBlank)
        cout << "CE";
    else {
        for (int i = 1; i < s.size() - 1; i++)
            cout << s[i];
    }
}
