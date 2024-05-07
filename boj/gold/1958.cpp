#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    auto l1 = s1.size();
    auto l2 = s2.size();
    auto l3 = s3.size();
    s1 = '0' + s1;
    s2 = '0' + s2;
    s3 = '0' + s3;
    int lcs[l1 + 1][l2 + 1][l3 + 1];

    for (int i = 0; i <= l1; i++) {
        for (int j = 0; j <= l2; j++) {
            for (int k = 0; k <= l3; k++) {
                if (i == 0 || j == 0 || k == 0)
                    lcs[i][j][k] = 0;
                else if (s1[i] == s2[j] && s2[j] == s3[k])
                    lcs[i][j][k] = lcs[i - 1][j - 1][k - 1] + 1;
                else
                    lcs[i][j][k] = max({ lcs[i - 1][j][k], lcs[i][j - 1][k], lcs[i][j][k - 1] });
            }
        }
    }

    cout << lcs[l1][l2][l3];
}
