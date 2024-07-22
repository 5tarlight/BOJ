#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
const int MAX = 10001;

int n, m;
int sccCnt, cnt;
int order[MAX * 2], scc[MAX * 2];
int ans[MAX];
bool done[MAX * 2];
vector<int> graph[MAX * 2];
stack<int> st;
vector<pii> ts;

int getNot(int n) {
    if (n % 2) return n + 1;
    else return n - 1;
}

int dfs(int cur) {
    order[cur] = ++cnt;
    st.push(cur);

    int ans = order[cur];
    for (int nxt : graph[cur]) {
        if (order[nxt] == 0)
            ans = min(ans, dfs(nxt));
        else if (!done[nxt])
            ans = min(ans, order[nxt]);
    }

    if (ans == order[cur]) {
        while (true) {
            int tmp = st.top();
            st.pop();
            scc[tmp] = sccCnt;
            done[tmp] = true;
            if (tmp == cur)
                break;
        }
        sccCnt++;
    }

    return ans;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u = u > 0 ? u * 2 - 1 : -u * 2;
        v = v > 0 ? v * 2 - 1 : -v * 2;
        graph[getNot(u)].push_back(v);
        graph[getNot(v)].push_back(u);
    }

    for (int i = 1; i <= n * 2; i++)
        if (order[i] == 0)
            dfs(i);

    for (int i = 1; i <= n; i++) {
        if (scc[i * 2 - 1] == scc[i * 2]) {
            cout << "0";
            return 0;
        }
    }

    cout << "1\n";

    memset(ans, -1, sizeof(ans));
    for (int i = 1; i <= n * 2; i++)
        ts.push_back(pii(scc[i], i));
    sort(ts.begin(), ts.end(), greater<>());

    for (auto p : ts) {
        int cur = p.second;
        if (ans[(cur + 1) / 2] == -1)
            ans[(cur + 1) / 2] = cur % 2 ? 0 : 1;
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}
