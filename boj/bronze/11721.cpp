#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (i > 0 && i % 10 == 0)
            cout << '\n';
        cout << s[i];
    }
}
