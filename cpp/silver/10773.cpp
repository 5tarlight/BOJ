#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k;
    cin >> k;

    stack<int> v;
    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;

        if (num == 0)
            v.pop();
        else
            v.push(num);
    }

    int sum = 0;
    while (!v.empty()) {
        sum += v.top();
        v.pop();
    }

    cout << sum;
}
