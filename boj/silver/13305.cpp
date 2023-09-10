#include <iostream>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n;
    cin >> n;
    long long r[n - 1];
    long long o[n];
    for (long long i = 0; i < n - 1; i++)
        cin >> r[i];
    for (long long i = 0; i < n; i++)
        cin >> o[i];

    long long pos = 1;
    long long fee = 0;
    while (pos < n) {
        for (long long i = pos; i < n; i++) {
            if (o[i] < o[pos - 1]) {
                long long dis = 0;
                for (long long j = pos-1; j < i; j++) {
                    dis += r[j];
                }

                fee += o[pos - 1] * dis;
                pos = i + 1;
                break;
            } else if (i == n - 1) {
                long long dis = 0;
                for (long long j = pos-1; j < n - 1; j++) {
                    dis += r[j];
                }

                fee += o[pos - 1] * dis;
                pos = n;
                break;
            }
        }
    }

    cout << fee;
}
