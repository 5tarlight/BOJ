#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int temp = 2;
    while (n--)
        temp += temp - 1;

    cout << temp * temp;
}
