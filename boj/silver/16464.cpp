#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    while (n--) {
        int k;
        cin >> k;

        if (__builtin_popcount(k) == 1)
            cout << "GoHanGang\n";
        else
            cout << "Gazua\n";
    }
}
