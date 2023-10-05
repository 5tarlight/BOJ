#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int mindp[3];
    int maxdp[3];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (i == 0) {
            maxdp[0] = mindp[0] = a;
            maxdp[1] = mindp[1] = b;
            maxdp[2] = mindp[2] = c;
            continue;
        }

        int max1 = maxdp[0];
        int max2 = maxdp[1];
        int max3 = maxdp[2];
        int min1 = mindp[0];
        int min2 = mindp[1];
        int min3 = mindp[2];

        maxdp[0] = max(max1, max2) + a;
        maxdp[1] = max(max1, max(max2, max3)) + b;
        maxdp[2] = max(max2, max3) + c;
        mindp[0] = min(min1, min2) + a;
        mindp[1] = min(min1, min(min2, min3)) + b;
        mindp[2] = min(min2, min3) + c;
    }

    cout << max(maxdp[0], max(maxdp[1], maxdp[2])) << ' ';
    cout << min(mindp[0], min(mindp[1], mindp[2]));
}
