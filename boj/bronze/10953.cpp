#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        int a = s[0] - '0';
        int b = s[s.length() - 1] - '0';

        cout << a + b << '\n';
    }
}
