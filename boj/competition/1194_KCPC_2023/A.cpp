#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    int c = 0;
    char sec[] = { 'K', 'O', 'R', 'E', 'A' };

    int l = 0;
    for (char ch : s) {
        if (ch == sec[c]) {
            l++;
            c++;
            if (c == 5)
                c = 0;
        }
    }

    cout << l;
}

