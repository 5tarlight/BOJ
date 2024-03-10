#include <iostream>

using namespace std;

#define DIV 1000000

long long a[1'500'001];

void fibo() {
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i <= 1'500'000; i++) {
        a[i] = (a[i - 1] + a[i - 2]) % DIV;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long n;
    cin >> n;
    fibo();

    cout << a[n % 1'500'000];
}
