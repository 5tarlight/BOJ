#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    for (char ch : s) {
        int i = (int)ch;
        int digit = 0;
        while (i > 0) {
            digit += i % 10;
            i /= 10;
        }

        while (digit--)
            cout << ch;
        cout << '\n';
    }
}
