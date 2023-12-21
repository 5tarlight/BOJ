#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    deque<int> d;
    int n;
    cin >> n;
    while (n--) {
        int op;
        cin >> op;

        if (op == 1) {
            int x;
            cin >> x;
            d.push_front(x);
        } else if (op == 2) {
            int x;
            cin >> x;
            d.push_back(x);
        } else if (op == 3) {
            if (d.empty())
                cout << "-1\n";
            else {
                cout << d.front() << '\n';
                d.pop_front();
            }
        } else if (op == 4) {
            if (d.empty())
                cout << "-1\n";
            else {
                cout << d.back() << '\n';
                d.pop_back();
            }
        } else if (op == 5)
            cout << d.size() << '\n';
        else if (op == 6)
            cout << (d.empty() ? 1 : 0) << '\n';
        else if (op == 7) {
            if (d.empty())
                cout << "-1\n";
            else
                cout << d.front() << '\n';
        } else {
            if (d.empty())
                cout << "-1\n";
            else
                cout << d.back() << '\n';
        }
    }
}
