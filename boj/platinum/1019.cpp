#include <iostream>

using namespace std;

long long ans[10];

int mul = 1;
void countDigit(int n) {
    while (n > 0) {
        // add 10 ^ d
        ans[n % 10] += mul;
        n /= 10;
    }
}

void solve(int a, int b) {
    while (a % 10 != 0 && a <= b) {
        countDigit(a);
        a++;
    }
    if (a > b) return;
    while (b % 10 != 9 && a <= b) {
        countDigit(b);
        b--;
    }
    if (a > b) return;
    a /= 10;
    b /= 10;
    for (int i = 0; i < 10; i++) {
        ans[i] += (b - a + 1) * mul;
    }
    mul *= 10;
    solve(a, b);
}

void print() {
    for (int i = 0; i < 10; i++)
        cout << ans[i] << ' ';
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    solve(1, n);
    print();
}
