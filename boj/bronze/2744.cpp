#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main() {
    string s;
    cin >> s;
    for (char ch : s) {
        if (ch >= 'A' && ch <= 'Z')
            printf("%c", ch + ('a' - 'A'));
        else
            printf("%c", ch - ('a' - 'A'));
    }
}
