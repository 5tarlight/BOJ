#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for (int i = 0; i < n - 3; i++) {
        if (s[i] == 'p' && s[i + 1] == 'P' && s[i + 2] == 'A' && s[i + 3] == 'p') {
            ans++;
            i += 3;
        }
    }

    cout << ans;
}
