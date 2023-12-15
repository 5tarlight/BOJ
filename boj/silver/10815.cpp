#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;
    map<int, bool> card;
    while (n--) {
        int v;
        cin >> v;
        card[v] = true;
    }

    int k;
    cin >> k;
    while (k--) {
        int v;
        cin >> v;
        if (card.find(v) == card.end())
            cout << "0 ";
        else
            cout << "1 ";
    }
}
