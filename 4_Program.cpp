// https://www.spoj.com/problems/ONP/
#include <iostream>
#include <stack>
#include <string>

int main () {
    int t;
    std::cin >> t;
    
    std::string operators = "+-*/^";

    while (t--) {
        std::string expression;

        std::cin >> expression;
        
        std::stack <char> op;
        
        for (char ch : expression) {
            if (ch == '(') {
                continue;
            }
            if (ch == ')') {
                if (op.empty()) {
                    break;
                }
                std::cout << op.top();
                op.pop();
            } else if (operators.find(ch) != std::string::npos) {
                op.push(ch);
            } else {
                std::cout << ch;
            }
        }

        std::cout << std::endl;
    }
    
    return 0;
}