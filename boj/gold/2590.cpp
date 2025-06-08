#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int c[7], b = 0;
    for (int i = 1; i <= 6; i++) if(!(cin >> c[i])) return 0;

    // 6×6
    b += c[6];
    // 5×5
    b += c[5];
    c[1] = max(0, c[1] - 11 * c[5]);

    // 4×4
    b += c[4];
    {
        int use2 = min(c[2], 5 * c[4]);
        c[2] -= use2;
        c[1] = max(0, c[1] - (5 * c[4] - use2) * 4);
    }

    // 3×3
    b += (c[3] + 3) / 4;
    if(int r = c[3] % 4){
        static int s2[4] = {0,5,3,1}, s1[4] = {0,7,6,5};
        int u = min(c[2], s2[r]);
        c[2] -= u;
        c[1] = max(0, c[1] - (s1[r] + (s2[r] - u) * 4));
    }

    // 2×2
    if(c[2]){
        b += (c[2] + 8) / 9;
        if(int m = c[2] % 9)
            c[1] = max(0, c[1] - (9 - m) * 4);
    }

    // 1×1
    if(c[1]) b += (c[1] + 35) / 36;

    cout << b << "\n";
}
