#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    pair<int, int> arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr, arr + n);

    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time <= arr[i].first)
            time = arr[i].first;
        time += arr[i].second;
    }

    cout << time;
}
