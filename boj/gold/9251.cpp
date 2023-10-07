#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str1, str2;
    cin >> str1 >> str2;
    str1 = '0' + str1;
    str2 = '0' + str2;
    int l1 = str1.length();
    int l2 = str2.length();
    int lcs[1001][1001];

    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < l2; j++) {
            if (i == 0 || j == 0) {
                lcs[i][j] = 0;
                continue;
            }

            if (str1[i] == str2[j])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }

    cout << lcs[l1 - 1][l2 - 1];
}
