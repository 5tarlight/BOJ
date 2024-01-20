#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int k, n;
    cin >> k >> n;
    map<long long, bool> cache;
    vector<long long> num(k);
    priority_queue<long long, vector<long long>, greater<>> q;

    for (int i = 0; i < k; i++)
        cin >> num[i];

    q.push(1);
    cache[1] = true;
    long long max = 0;

    while (n--) {
        long long top = q.top();
        q.pop();

        for (long long i : num) {
            long long nxt = top * i;

            if (cache.count(nxt))
                continue;
            if (q.size() > n && max <= nxt)
                continue;

            q.push(nxt);
            max = max > nxt ? max : nxt;
            cache[nxt] = true;
        }
    }

    cout << q.top();
}
