#include <iostream>
#include <map>

using namespace std;

map<int, int> m;

int normalize(int x) {
    while (x % 2 == 0)
        x /= 2;
    return x;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    while (n--) {
        int num;
        cin >> num;
        m[normalize(num)]++;
    }

    int ans = 0;
    for (auto &p : m) {
        if (p.second > ans)
            ans = p.second;
    }

    cout << ans;
}
