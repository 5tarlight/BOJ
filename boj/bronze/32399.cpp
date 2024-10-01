#include "bits/stdc++.h"

using namespace std;

int main() {
    string s;
    cin >> s;

    if (s == "1()")
        cout << 1;
    else if (s == "1)(")
        cout << 1;
    else if (s == "(1)")
        cout << 0;
    else if (s == "()1")
        cout << 1;
    else if (s == ")(1")
        cout << 1;
    else if (s == ")1(")
        cout << 2;
}
