#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    while (s.size() < t.size()) {
        if (t.back() == 'A')
            t.pop_back();
        else {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }

    if (t == s)
        cout << 1;
    else
        cout << 0;
}
