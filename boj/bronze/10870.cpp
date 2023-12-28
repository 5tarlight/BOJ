#include <iostream>

using namespace std;

long long fibo(long long n) {
    if (n == 1 || n == 2)
        return 1;
    else
        return fibo(n - 1) + fibo(n - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << fibo(n);
}
