#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    pair<int, int> p1, p2, p3;
    cin >> p1.first >> p1.second;
    cin >> p2.first >> p2.second;
    cin >> p3.first >> p3.second;

    double dx1 = p2.first - p1.first;
    double dy1 = p2.second - p1.second;
    double dx2 = p3.first - p2.first;
    double dy2 = p3.second - p2.second;

    if (dx1 * dy2 == dx2 * dy1) {
        cout << "WHERE IS MY CHICKEN?";
    } else {
        cout << "WINNER WINNER CHICKEN DINNER!";
    }
}
