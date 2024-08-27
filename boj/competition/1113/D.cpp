#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int s, n , m;
    cin >> s >> n >> m;
    
    int cap = s;
    int cur = 0;
    
    for (int i = 0; i < n + m; i++) {
        int c;
        cin >> c;
        
        if (c == 1) {
            cur++;
            if (cur > cap)
                cap *= 2;
        } else {
            cur--;
        }
    }
    
    cout << cap;
}