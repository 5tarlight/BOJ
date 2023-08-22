#include <string>
#include <iostream>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::queue<int> queue;

    for (int i = 0; i < n; i++) {
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "push") {
            int n;
            std::cin >> n;
            queue.push(n);
        } else if (cmd == "pop") {
            if (!queue.empty()) {
                std::cout << queue.front() << "\n";
                queue.pop();
            } else {
                std::cout << "-1\n";
            }
        } else if (cmd == "size") {
            std::cout << queue.size() << "\n";
        } else if (cmd == "empty") {
            int empty = queue.empty() ? 1 : 0;
            std::cout << empty << "\n";
        } else if (cmd == "back") {
            if (queue.empty()) {
                std::cout << "-1\n";
            } else {
                std::cout << queue.back() << "\n";
            }
        } else if (cmd == "front") {
            if (queue.empty()) {
                std::cout << "-1\n";
            } else {
                std::cout << queue.front() << "\n";
            }
        }
    }
}