#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    s = "0" + s;
    int sum[s.size()];
    sum[0] = s[0] - '0';
    for (int i = 1; i < s.size(); i++)
        sum[i] = sum[i - 1] + s[i] - '0';

    int ans = -1;
    for (int l = 0; l < s.size(); l++) {
        for (int r = l + 2; r < s.size(); r += 2) {
            int mid = (l + r) / 2;
            int lsum = sum[mid] - sum[l];
            int rsum = sum[r] - sum[mid];
            if (lsum == rsum && r - l + 1 > ans)
                ans = r - l;
        }
    }

    cout << ans;
}
