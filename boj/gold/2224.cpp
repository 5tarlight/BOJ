#include <iostream>
#include <string>
#include <vector>

using namespace std;

int toIdx(char ch) {
    if (ch <= 'Z')
        return ch - 'A';
    return ch - 'a' + 26;
}

char toCh(int x) {
    if (x < 26)
        return 'A' + x;
    return 'a' + (x - 26);
}

const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    int dist[52][52];
    for (int i = 0; i < 52; i++)
        fill(dist[i], dist[i] + 52, INF);
    cin.ignore();
    while (n--) {
        char a, b;
        string s;
        getline(cin, s);
        a = s[0];
        b = s[s.size() - 1];
        int ia = toIdx(a);
        int ib = toIdx(b);
        dist[ia][ib] = 0;
    }

    for (int k = 0; k < 52; k++)
        for (int i = 0; i < 52; i++)
            for (int j = 0; j < 52; j++)
                if (dist[i][k] == 0 && dist[k][j] == 0)
                    dist[i][j] = 0;

    vector<pair<int, int>> ans;
    for (int i = 0; i < 52; i++)
        for (int j = 0; j < 52; j++)
            if (dist[i][j] == 0 && i != j) {
                ans.push_back({ i, j });
            }

    printf("%lld\n", ans.size());
    for (auto &p : ans)
        cout << toCh(p.first) << " => " << toCh(p.second) << '\n';
}
