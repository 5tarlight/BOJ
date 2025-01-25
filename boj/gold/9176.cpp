#include "bits/stdc++.h"

using namespace std;

using ll = long long;

vector<pair<pair<int, ll>, vector<ll>>> ans = {
    {{11, 2047}, {23, 89}},
    {{23, 8388607}, {47, 178481}},
    {{29, 536870911}, {233, 1103, 2089}},
    {{37, 137438953471}, {223, 616318177}},
    {{41, 2199023255551}, {13367, 164511353}},
    {{43, 8796093022207}, {431, 9719, 2099863}},
    {{47, 140737488355327}, {2351, 4513, 13264529}},
    {{53, 9007199254740991}, {6361, 69431, 20394401}},
    {{59, 576460752303423487}, {179951, 3203431780337}}
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (auto &[p, v] : ans) {
        if (p.first > n) break;

        for (int j = 0; j < v.size(); j++) {
            cout << v[j];
            if (j != v.size() - 1) cout << " * ";
        }
        cout << " = " << p.second << " = ( 2 ^ " << p.first << " ) - 1\n";
    }
}
