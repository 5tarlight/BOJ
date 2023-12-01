#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    string s;
    int jin;
    cin >> s >> jin;

    int num = 0;
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        int value;
        if (ch >= '0' && ch <= '9') {
            value = ch - '0';
        } else {
            value = 10 + ch - 'A';
        }

        num += value * (int)pow(jin, s.length() - i - 1);
    }

    cout << num;
}
