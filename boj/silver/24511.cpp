#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int type[n];
    for (int i = 0; i < n; i++)
        cin >> type[i];

    deque<int> d;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (type[i] == 0)
            d.push_back(x);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        d.push_front(x);

        cout << d.back() << ' ';
        d.pop_back();
    }
}
