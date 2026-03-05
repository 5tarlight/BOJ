#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

typedef pair<int, int> p;

double area(p &a, p &b, p &c) {
    return abs(
        a.first * (b.second - c.second) +
        b.first * (c.second - a.second) +
        c.first * (a.second - b.second)
    ) / 2.0;
}

bool isInside(p &a, p &b, p &c, p &p) {
    double abc = area(a, b, c);
    double abp = area(a, b, p);
    double acp = area(a, c, p);
    double bcp = area(b, c, p);
    return abc == abp + acp + bcp;
}

int main() {
    fio();

    p a, b, c;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;

    int ans = 0;
    int t; cin >> t;
    while (t--) {
        p p;
        cin >> p.first >> p.second;
        if (isInside(a, b, c, p)) ans++;
    }

    cout << fixed << setprecision(1) << area(a, b, c) << '\n';
    cout << ans;
}
