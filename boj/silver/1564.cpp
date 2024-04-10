#include <iostream>

using namespace std;

void mod(long long *n) {
    while (*n % 10 == 0)
        *n /= 10;
}

int main() {
    int n;
    cin >> n;
    long long t = 1;
    for (int i = 2; i <= n; i++) {
        t *= i;
        mod(&t);
        t %= (long long)1e12;
    }
    printf("%05lld\n", t % 100000);
}
