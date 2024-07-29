#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[500001];
vector<int> rev[500001];
bool visited[500001];
int n, m, x;
int ansA, ansB;

void cntUpper(int cur) {
    ansA++;
    for (int nxt : adj[cur]) {
        if (visited[nxt]) continue;
        visited[nxt] = true;
        cntUpper(nxt);
    }
}

void cntLower(int cur) {
    ansB++;
    for (int nxt : rev[cur]) {
        if (visited[nxt]) continue;
        visited[nxt] = true;
        cntLower(nxt);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> x;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
        rev[a].push_back(b);
    }

    visited[x] = true;
    cntUpper(x);
    cntLower(x);

    cout << ansA << ' ' << n - ansB + 1;
}
