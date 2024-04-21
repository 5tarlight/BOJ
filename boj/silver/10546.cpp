#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    map<string, int> cnt;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cnt[s]++;
    }

    for (int i = 0; i < n - 1; i++) {
        string s;
        cin >> s;
        cnt[s]--;
    }

    for (auto& [key, value] : cnt) {
        if (value != 0) {
            cout << key;
            break;
        }
    }
}
