#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    string str[5];
    unsigned long maxl = 0;
    for (int i = 0; i < 5; i++) {
        cin >> str[i];

        if (str[i].length() > maxl)
            maxl = str[i].length();
    }

    for (int i = 0; i < maxl; i++) {
        for (int j = 0; j < 5; j++) {
            if (str[j].length() < i + 1)
                continue;
            else
                cout << str[j][i];
        }
    }
}
