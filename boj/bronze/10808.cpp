#include <iostream>
#include <string>

using namespace std;

int cnt[26];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    for (char ch : s)
        cnt[ch - 'a']++;

    for (int v : cnt)
        cout << v << ' ';
}
