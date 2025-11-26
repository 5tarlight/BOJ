#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

bool sieve[10001];
vector<int> p;

bool is_prime(int n) {
    if (n <= 10000) return sieve[n];
    for (int prime : p) {
        if (prime * prime > n) break;
        if (n % prime == 0) return false;
    }
    return true;
}

bool is_palindrome(int n) {
    int original = n;
    int rev = 0;

    while (n > 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }

    return original == rev;
}

int main() {
    memset(sieve, true, sizeof(sieve));
    sieve[0] = sieve[1] = false;
    for (int i = 2; i <= 10000; ++i) {
        if (sieve[i]) {
            p.push_back(i);
            for (int j = i * i; j <= 10000; j += i)
                sieve[j] = false;
        }
    }

    int a, b;
    cin >> a >> b;

    for (int i = a; i <= b; ++i) {
        if (i % 2 == 0) continue;
        if (is_palindrome(i) && is_prime(i))
            cout << i << '\n';
    }

    cout << -1;
    fio();
}
