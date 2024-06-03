#include <iostream>
#include <string>

using namespace std;

string s0 = "moo";

char moo(int n, int k, int len) {
    if (n <= 3) {
        return s0[n - 1];
    }

    int newl = len * 2 + k + 3;
    if (newl < n) {
        return moo(n, k + 1, newl);
    } else {
        if (n > len && n <= len + k + 3) {
            if (n == len + 1) {
                return 'm';
            } else {
                return 'o';
            }
        } else {
            return moo(n - len - k - 3, 1, 3);
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cout << moo(n, 1, 3);
}
