#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string str;
    cin >> n >> str;

    int ans = 0;
    int l = 0;
    int s = 0;

    for (int i = 0; i < n; i++) {
        if (str[i] == 'S')
            s++;
        else if (str[i] == 'L')
            l++;
        else if (str[i] == 'R') {
            if (l == 0)
                break;
            ans++;
            l--;
        } else if (str[i] == 'K') {
            if (s == 0)
                break;
            ans++;
            s--;
        } else
            ans++;
    }

    cout << ans;
}
