#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    map<string, bool> card;
    while (n--) {
        string v;
        cin >> v;
        card[v] = true;
    }

    int cnt = 0;
    while (k--) {
        string v;
        cin >> v;
        if (card.find(v) != card.end())
            cnt++;
    }

    cout << cnt;
}
