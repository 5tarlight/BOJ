#include <iostream>

using namespace std;

int k, n, v[10001];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> k >> n;
    long high = -1, low = 1;

    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;
        v[i] = num;

        if (num > high)
            high = num;
    }

    long answer = 0;
    while (low <= high) {
        long mid = (low + high) / 2;

        int count = 0;
        for (int i = 0; i < k; i++)
            count += v[i] / mid;

        if (count >= n) {
            low = mid + 1;

            if (answer < mid)
                answer = mid;
        } else
            high = mid - 1;
    }

    cout << answer;
}
