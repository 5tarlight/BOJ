#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
bool card[1000001];
int scores[1000001];
int n;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    a.reserve(n);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        a.push_back(num);
        card[num] = true;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 2 * a[i]; j <= 1000000; j += a[i]) {
            if (card[j]) {
                scores[a[i]]++;
                scores[j]--;
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << scores[a[i]] << ' ';
}
