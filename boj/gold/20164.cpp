#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) {
    return { a.first + b.first, a.second + b.second };
}

pair<int, int> operator+(const pair<int, int>& a, int b) {
    return { a.first + b, a.second + b };
}

pair<int, int> cntEven(string s) {
    if (s.length() == 1) {
        int ans = (s[0] - '0') % 2 != 0;
        return { ans, ans };
    } else if (s.length() == 2) {
        int tmp = s[0] - '0' + s[1] - '0';

        int cnt = 0;
        if ((s[0] - '0') % 2 != 0)
            cnt++;
        if ((s[1] - '0') % 2 != 0)
            cnt++;

        return cntEven(to_string(tmp)) + cnt;
    }

    // Split string into 3 parts
    int n = s.length();
    int minCnt = 1e9;
    int maxCnt = 0;

    int cnt = 0;
    for (char ch : s)
        if ((ch - '0') % 2 != 0)
            cnt++;

    for (int i = 1; i <= n - 2; i++) {
        for (int j = 1; j + i <= n - 1; j++) {
            string s1 = s.substr(0, i);
            string s2 = s.substr(i, j);
            string s3 = s.substr(i + j, n - i - j);

            int tmp = stoi(s1) + stoi(s2) + stoi(s3);
            auto ans = cntEven(to_string(tmp)) + cnt;

            minCnt = min(minCnt, ans.first);
            maxCnt = max(maxCnt, ans.second);
        }
    }

    return { minCnt, maxCnt };
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    auto ans = cntEven(s);
    cout << ans.first << " " << ans.second << endl;
}
