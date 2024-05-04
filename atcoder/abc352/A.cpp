#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, x, y, z;
    cin >> n >> x >> y >> z;

    if (
            z >= x && z <= y ||
            z <= x && z >= y
            )
        cout << "Yes";
    else
        cout << "No";
}
