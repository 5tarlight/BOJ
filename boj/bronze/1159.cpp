#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int cnt[26];
    fill(cnt, cnt + 26, 0);
    int n;
    cin >> n;
    while (n--) {
        string name;
        cin >> name;
        cnt[name[0] - 'a']++;
    }

    int printed = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] >= 5) {
            cout << (char)('a' + i);
            printed++;
        }
    }

    if (printed == 0) {
        cout << "PREDAJA";
    }
}
