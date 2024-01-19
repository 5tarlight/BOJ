#include <iostream>
#include <vector>

using namespace std;

#define DIV 1000000007
typedef long long ll;
typedef vector<vector<ll>> g;

g mul(g &v1, g &v2) {
    g ans(8, vector<ll>(8));

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            ll e = 0;

            for(int k=0; k<8; k++){
                e += (v1[i][k] * v2[k][j]);
                e %= DIV;
            }
            ans[i][j] = e % DIV;
        }
    }

    return ans;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int d;
    cin >> d;
    g ans(8, vector<ll>(8));
    for (int i = 0; i < 8; i++)
        ans[i][i] = 1;

    g graph = {
            {0, 1, 1, 0, 0, 0, 0, 0},
            {1, 0, 1, 1, 0, 0, 0, 0},
            {1, 1, 0, 1, 1, 0, 0, 0},
            {0, 1, 1, 0, 1, 1, 0, 0},
            {0, 0, 1, 1, 0, 1, 0, 1},
            {0, 0, 0, 1, 1, 0, 1, 0},
            {0, 0, 0, 0, 0, 1, 0, 1},
            {0, 0, 0, 0, 1, 0, 1, 0}
    };

    while (d) {
        if (d & 1) {
            ans = mul(ans, graph);
            d--;
        }

        graph = mul(graph, graph);
        d /= 2;
    }

    cout << ans[0][0];
}
