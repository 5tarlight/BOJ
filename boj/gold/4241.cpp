#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 1000;
vector<bool> is_prime(10001);
vector<int> seq;
vector<bool> used;
int n, m, d;
bool found;

void sieve() {
    fill(is_prime.begin(), is_prime.end(), true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= 10000; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= 10000; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

bool is_valid(int idx) {
    for (int length = 2; length <= d && idx - length + 1 >= 0; ++length) {
        int sum = 0;
        for (int i = 0; i < length; ++i) {
            sum += seq[idx - i];
        }
        if (is_prime[sum]) {
            return false;
        }
    }
    return true;
}

void backtrack(int idx) {
    if (found) return;
    if (idx == seq.size()) {
        for (int i = 0; i < seq.size(); ++i) {
            if (i > 0) cout << ",";
            cout << seq[i];
        }
        cout << endl;
        found = true;
        return;
    }

    for (int i = n; i <= m; ++i) {
        if (!used[i - n]) {
            seq[idx] = i;
            if (is_valid(idx)) {
                used[i - n] = true;
                backtrack(idx + 1);
                used[i - n] = false;
            }
        }
    }
}

int main() {
    sieve();

    while (true) {
        cin >> n >> m >> d;
        if (n == 0 && m == 0 && d == 0) break;

        int size = m - n + 1;
        seq.resize(size);
        used.assign(size, false);
        found = false;

        backtrack(0);

        if (!found) {
            cout << "No anti-prime sequence exists." << endl;
        }
    }

    return 0;
}
