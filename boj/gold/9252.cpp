#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s1, s2;
    cin >> s1 >> s2;
    auto l1 = s1.size();
    auto l2 = s2.size();
    s1 = '0' + s1;
    s2 = '0' + s2;
    int lcs[l1 + 1][l2 + 1];

    for (int i = 0; i <= l1; i++) {
        for (int j = 0; j <= l2; j++) {
            if (i == 0 || j == 0)
                lcs[i][j] = 0;
            else if (s1[i] == s2[j])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }

    cout << lcs[l1][l2] << '\n';

    vector<char> ans;
    auto i = l1, j = l2;
    while (lcs[i][j]) {
        if (lcs[i - 1][j] == lcs[i][j])
            i--;
        else if (lcs[i][j - 1] == lcs[i][j])
            j--;
        else {
            ans.push_back(s1[i]);
            i--;
            j--;
        }
    }

    reverse(ans.begin(), ans.end());
    for (char ch : ans)
        cout << ch;
}
