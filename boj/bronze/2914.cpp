#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, i;
    cin >> a >> i;
    cout << a * (i - 1) + 1;
}
