#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    n *= 2;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int min = 1e9;
    for (int i = 0; i < n / 2; i++) {
        int sum = arr[i] + arr[n - i - 1];
        if (sum < min) {
            min = sum;
        }
    }

    cout << min;
}
