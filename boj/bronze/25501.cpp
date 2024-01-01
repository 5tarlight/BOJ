#include <iostream>
#include <cstring>

using namespace std;

int cnt = 0;

int recursion(const char * s, int l, int r) {
    cnt++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}
int isPalindrome(const char * s) {
    return recursion(s, 0, strlen(s) - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cnt = 0;
        string s;
        cin >> s;
        cout << isPalindrome(s.c_str()) << " " << cnt << "\n";
    }
}
