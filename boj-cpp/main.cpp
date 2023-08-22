#include <string>
#include <iostream>
#include <stack>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::stack<int> stack;

    for (int i = 0; i < n; i++) {
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "push") {
            int n;
            std::cin >> n;
            stack.push(n);
        } else if (cmd == "pop") {
            if (!stack.empty()) {
                std::cout << stack.top() << "\n";
                stack.pop();
            } else {
                std::cout << "-1\n";
            }
        } else if (cmd == "size") {
            std::cout << stack.size() << "\n";
        } else if (cmd == "empty") {
            int empty = stack.empty() ? 1 : 0;
            std::cout << empty << "\n";
        } else if (cmd == "top") {
            if (stack.empty()) {
                std::cout << "-1\n";
            } else {
                std::cout << stack.top() << "\n";
            }
        }
    }
}