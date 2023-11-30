#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int l = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'c' || s[i] == 'l' || s[i] == 'n' || s[i] == 's' || s[i] == 'z') {
            l++;
            i++;
        } else if (s[i + 1] == '-') {
            l++;
            i++;
        } else {
            l++;
            i += 2;
        }
    }

    cout << l;
}
