#include <iostream>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    cin >> n;

    int count = 0, answer = 0;

    while (count != n) {
        answer++;

        int temp = answer;

        while (temp) {
            if (temp % 1000 == 666) {
                count++;
                break;
            } else {
                temp /= 10;
            }
        }
    }

    cout << answer;
}
