#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int year;
        cin >> year;

        if ((year + 1) % (year % 100) == 0)
            cout << "Good\n";
        else
            cout << "Bye\n";
    }
}
