#include <string>
#include <iostream>
#include <deque>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::deque<int> deque;

    for (int i = 0; i < n; i++) {
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "push_front") {
            int n;
            std::cin >> n;
            deque.push_front(n);
        } else if (cmd == "push_back") {
            int n;
            std::cin >> n;
            deque.push_back(n);
        } else if (cmd == "pop_front") {
            if (!deque.empty()) {
                std::cout << deque.front() << "\n";
                deque.pop_front();
            } else {
                std::cout << "-1\n";
            }
        } else if (cmd == "pop_back") {
            if (!deque.empty()) {
                std::cout << deque.back() << "\n";
                deque.pop_back();
            } else {
                std::cout << "-1\n";
            }
        } else if (cmd == "size") {
            std::cout << deque.size() << "\n";
        } else if (cmd == "empty") {
            int empty = deque.empty() ? 1 : 0;
            std::cout << empty << "\n";
        } else if (cmd == "front") {
            if (deque.empty()) {
                std::cout << "-1\n";
            } else {
                std::cout << deque.front() << "\n";
            }
        } else if (cmd == "back") {
            if (deque.empty()) {
                std::cout << "-1\n";
            } else {
                std::cout << deque.back() << "\n";
            }
        }
    }
}