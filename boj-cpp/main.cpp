#include <iostream>

using namespace std;

typedef __float128 llf;
typedef __int128 lld;
typedef long double lf;
llf pi = 3.1415926535897932384626Q;

llf sin(llf a) {
    a -= lld(a / pi) * pi;
    llf r = a;
    llf x = a;
    llf f = -a * a;

    for (llf d = 2; d < 30; d += 2)
        r += x *= f / (d * (d + 1));

    return r;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    pi *= 2;
    lf a, b, c;
    cin >> a >> b >> c;

    llf A = a;
    llf B = b;
    llf C = c;
    llf U = 1000000;
    llf D = 0.5;
    llf l = (C - B) / A;
    llf r = (C + B) / A;
    int t = 80;

    while (t--) {
        llf mid = (l + r) / 2;
        llf V = A * mid + b * sin(mid);

        (V < C ? l : r) = mid;
    }

    auto ans = lf(lld(U * r + D) / U);
    cout << ans;
}
