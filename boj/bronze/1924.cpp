#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    string week[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

    int m, d;
    cin >> m >> d;
    for (int i = 1; i < m; i++)
        d += days[i];

    cout << week[d % 7];
}
