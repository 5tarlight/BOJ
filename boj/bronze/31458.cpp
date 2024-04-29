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
        int left = 0;
        int right = 0;
        int number = -1;

        for (char ch : s) {
            if (number == -1 && ch == '!')
                left++;
            else if (number != -1 && ch == '!')
                right++;
            else
                number = ch - '0';
        }

        if (right > 0)
            number = 1;

        if (left > 0) {
            if (left & 1) {
                if (number == 1)
                    cout << "0\n";
                else
                    cout << "1\n";
            } else {
                if (number == 1)
                    cout << "1\n";
                else
                    cout << "0\n";
            }
        } else {
            cout << number << '\n';
        }
    }
}
