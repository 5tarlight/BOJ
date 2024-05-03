#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int bigdata = 0;
    int security = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'b') {
            bigdata++;
            i += 6;
        } else {
            security++;
            i += 7;
        }
    }

    if (bigdata > security)
        cout << "bigdata?";
    else if (bigdata < security)
        cout << "security!";
    else
        cout << "bigdata? security!";
}
