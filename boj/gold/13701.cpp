#include <iostream>
#include <bitset>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    bitset<33554432> bs;
    int n;

    while (~scanf("%d", &n)) {
        if (!bs[n])
            printf("%d ", n);
        bs[n] = true;
    }
}
