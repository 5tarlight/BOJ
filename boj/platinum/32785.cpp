#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <class OStream, class T, class U> OStream &operator<<(OStream &os, const std::pair<T, U> &pa) { return os << '(' << pa.first << ',' << pa.second << ')'; }
#ifdef YEAHx4
#define dbg(x) std::cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#else
#define dbg(x) ((void)0)
#endif

int main() {
    fio();

    int n;
    cin >> n;
    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> f[i];

    vector<bool> visited(n + 1, false), inStack(n + 1, false);
    vector<int> cycleLen(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int cur = i;
            vector<int> chain;
            while (true) {
                chain.push_back(cur);
                inStack[cur] = true;
                visited[cur] = true;
                int nxt = f[cur];
                if (!visited[nxt]) {
                    cur = nxt;
                    continue;
                }
                else if (inStack[nxt]) {
                    int pos = 0;
                    for (int j = 0; j < chain.size(); j++) {
                        if (chain[j] == nxt) {
                            pos = j;
                            break;
                        }
                    }
                    int len = chain.size() - pos;
                    for (int j = pos; j < chain.size(); j++)
                        cycleLen[chain[j]] = len;
                    break;
                }
                else {
                    break;
                }
            }
            for (int node : chain)
                inStack[node] = false;
        }
    }

    vector<int> inCount(n + 1, 0);
    for (int x = 1; x <= n; x++)
        inCount[f[x]]++;

    vector<long long> freqCycle(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (cycleLen[i] > 0)
            freqCycle[cycleLen[i]] += inCount[i];
    }

    int MAX = 2000000;
    vector<long long> F(MAX + 1, 0);
    for (int d = 1; d <= n; d++) {
        if (freqCycle[d] != 0) {
            for (int j = d; j <= MAX; j += d)
                F[j] += freqCycle[d];
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int q;
        cin >> q;
        if (q == 1)
            cout << n << "\n";
        else {
            int r = q - 1;
            cout << F[r] << "\n";
        }
    }
}
