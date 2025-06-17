#include <bits/stdc++.h>
using namespace std;
void fio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    fio();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<long long, long long>> points(n);
        for(int i = 0; i < n; i++){
            cin >> points[i].first >> points[i].second;
        }

        int half = n / 2;
        double answer = 1e18;
        int lim = 1 << n;

        for(int mask = 0; mask < lim; mask++){
            if(!(mask & 1)) continue;
            if(__builtin_popcount(mask) != half) continue;

            long long sx = 0, sy = 0;
            for(int i = 0; i < n; i++){
                int w = (mask & (1 << i)) ? 1 : -1;
                sx += w * points[i].first;
                sy += w * points[i].second;
            }
            answer = min(answer, sqrt(double(sx) * sx + double(sy) * sy));
        }

        cout << fixed << setprecision(10) << answer << "\n";
    }
    return 0;
}
