#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int a, p;
int getNext(int prev) {
    int sum = 0;
    while (prev) {
        sum += pow(prev % 10, p);
        prev /= 10;
    }

    return sum;
};

bool visited[1000000];
int idx[1000000];

int main() {
    fio();

    cin >> a >> p;
    int prev = a;
    int cur = a;

    int cnt = 0;
    while (!visited[cur]) {
        visited[cur] = true;
        idx[cur] = cnt++;
        prev = cur;
        cur = getNext(cur);
    }

    cout << idx[cur] << '\n';
}
