#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int w, h, n;
    cin >> w >> h >> n;

    vector<int> s;

    int l = 2 * (w + h);

    for (int i = 0; i < n; i++) {
        int dir, dist;
        cin >> dir >> dist;

        if (dir == 1)
            s.push_back(dist);
        else if (dir == 2)
            s.push_back(w + h + (w - dist));
        else if (dir == 3)
            s.push_back(l - dist);
        else if (dir == 4)
            s.push_back(w + dist);
    }

    int d_dir, d_dist;
    cin >> d_dir >> d_dist;

    int d_pos;
    if (d_dir == 1)
        d_pos = d_dist;
    else if (d_dir == 2)
        d_pos = w + h + (w - d_dist);
    else if (d_dir == 3)
        d_pos = l - d_dist;
    else if (d_dir == 4)
        d_pos = w + d_dist;

    long long ans = 0;

    for (int store_pos : s) {
        int a = abs(d_pos - store_pos);
        int b = l - a;
        ans += min(a, b);
    }

    cout << ans;

    return 0;
}
