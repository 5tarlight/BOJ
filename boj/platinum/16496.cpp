#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string nums[1001];

bool cmp(const string& a, const string& b) {
    string s1 = a + b;
    string s2 = b + a;

    return s1 > s2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    bool allZero = true;

    for (int i = 0; i < n; i++) {
        string num;
        cin >> num;
        if (allZero && num != "0")
            allZero = false;
        nums[i] = num;
    }

    if (allZero) {
        cout << 0;
        return 0;
    }

    sort(nums, nums + n, cmp);

    for (int i = 0; i < n; i++)
        cout << nums[i];
}
