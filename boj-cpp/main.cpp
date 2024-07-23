#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

string nth_palindrome(int64_t N) {
    if (N == 1) {
        return "0";
    }
    N--;

    int length = 1;
    int64_t count = 9;

    while (N >= count) {
        N -= count;
        length++;
        count = 9 * pow(10, (length - 1) / 2);
    }

    int64_t half = pow(10, (length - 1) / 2) + N;
    string half_str = to_string(half);

    string palindrome = half_str;
    if (length % 2 == 1) {
        half_str.pop_back();
    }
    reverse(half_str.begin(), half_str.end());
    palindrome += half_str;

    return palindrome;
}

int main() {
    int64_t N;
    cin >> N;

    cout << nth_palindrome(N);


    return 0;
}
