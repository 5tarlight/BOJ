#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, char> d = {
        {"AA", 'A'},
        {"AG", 'G'},
        {"AC", 'A'},
        {"AT", 'G'},
        {"GA", 'C'},
        {"GG", 'G'},
        {"GC", 'T'},
        {"GT", 'A'},
        {"CA", 'A'},
        {"CG", 'T'},
        {"CC", 'C'},
        {"CT", 'G'},
        {"TA", 'G'},
        {"TG", 'A'},
        {"TC", 'G'},
        {"TT", 'T'}
    };

    int n;
    cin >> n;
    string s;
    cin >> s;

    while (s.length() > 1) {
        s = s.substr(0, s.length() - 2) + d[s.substr(s.length() - 2, 2)];
    }

    cout << s << endl;

    return 0;
}
