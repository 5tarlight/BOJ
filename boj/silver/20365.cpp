#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int cnt = 1;
    char prev = s[0];
    for (int i = 1; i < n; i++) {
        if (prev != s[i]) {
            cnt++;
            prev = s[i];
        }
    }

    cout << cnt / 2 + 1;
}
