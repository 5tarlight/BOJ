#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

#define X first
#define Y second

typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<p, p> line;

int ccw(p &a, p &b, p &c) {
    ll temp = a.X * b.Y + b.X * c.Y + c.X * a.Y;
    temp -= a.Y * b.X + b.Y * c.X + c.Y * a.X;

    if (temp > 0)
        return 1;
    else if (temp == 0)
        return 0;
    else
        return -1;
}

bool isCross(p a, p b, p c, p d) {
    ll a1 = ccw(a, b, c) * ccw(a, b, d);
    ll a2 = ccw(c, d, a) * ccw(c, d, b);

    if (a1 <= 0 && a2 <= 0) {
        if (
            a.X > c.X && a.X > d.X && b.X > c.X && b.X > d.X ||
            c.X > a.X && c.X > b.X && d.X > a.X && d.X > b.X ||
            a.Y > c.Y && a.Y > d.Y && b.Y > c.Y && b.Y > d.Y ||
            c.Y > a.Y && c.Y > b.Y && d.Y > a.Y && d.Y > b.Y
        )
            return false;
        else
            return true;
    } else
        return false;
}

int n;
line lines[3001];
int parents[3001];
int sizes[3001];

int find(int a) {
    if (a == parents[a])
        return a;
    else
        return parents[a] = find(parents[a]);
}

void uni(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if (pa < pb)
        parents[b] = pa;
    else
        parents[a] = pb;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> lines[i].X.X >> lines[i].X.Y >> lines[i].Y.X >> lines[i].Y.Y;
        parents[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (isCross(lines[i].X, lines[i].Y, lines[j].X, lines[j].Y)) {
                uni(i, j);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        sizes[find(i)]++;
    }

    int groups = 0;
    int maxSize = 0;
    for (int i = 1; i <= n; i++) {
        if (sizes[i] != 0) {
            groups++;
            maxSize = max(maxSize, sizes[i]);
        }
    }

    cout << groups << '\n' << maxSize;
}
