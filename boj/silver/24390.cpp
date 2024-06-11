#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int m, s;
    scanf("%d:%d", &m, &s);

    int ans = 1;
    ans += m / 10 + m % 10;
    ans += s < 30 ? s / 10 : (s - 30) / 10;

    cout << ans;
}
