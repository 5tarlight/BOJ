#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int g;
    cin >> g;
    n--;
    while (n--) {
        int num;
        cin >> num;
        g = gcd(g, num);
    }

    for (int i = 1; i <= g; i++)
        if (g % i == 0)
            cout << i << '\n';
}
