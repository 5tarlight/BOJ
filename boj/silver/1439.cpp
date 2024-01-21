#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int zero = 0;
    int one = 0;
    char last = s[0];

    if (last == '1')
        one++;
    else
        zero++;

    for (char ch : s) {
        if (ch != last) {
            if (ch == '1')
                one++;
            else
                zero++;
            last = ch;
        }
    }

    if (zero + one == 1)
        cout << 0;
    else
        cout << (zero < one ? zero : one);
}
