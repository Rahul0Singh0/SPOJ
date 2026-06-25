// https://www.spoj.com/problems/ARITH/
// We need to better solution cause this occured run time error 
/**
 * I think problem is bigger number multiplication
 * 123456789123456789123456789 * 987654321987654321987654321
 * long long can't handle of above multiplication result
 */
#include <iostream> 
#include <string>
#include <unordered_set>
#include <vector>

std::unordered_set <char> numbers {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

std::vector<std::string> findOperator(std::string str) {
    std::string firstOperand = "";
    std::string op = "";
    std::string secondOperand = "";
    bool isOpFound = false;
    for (char ch : str) {
        if (isOpFound) {
            secondOperand += ch;
        }
        if (numbers.find(ch) == numbers.end()) {
            op += ch;
            isOpFound = true;
        } else if(!isOpFound) {
            firstOperand += ch;
        }
    }
    return {op, firstOperand, secondOperand};
}

void printLine(int n) {
    std::string res = "";
    for (int i = 0; i < n; i++) {
        res += '-';
    }

    std::cout << res << std::endl;
}

void printSpace(int n) {
    std::string res = "";
    for (int i = 0; i < n; i++) {
        res += ' ';
    }

    std::cout << res;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string str;

        std::cin >> str;

        std::vector <std::string> result = findOperator(str);
        if (!result.size()) {
            return 0;
        }

        if (result[0] == "+") {
            std::string res = std::to_string(std::stoi(result[1]) + std::stoi(result[2]));
            std::cout << " " << result[1] << std::endl;
            std::cout << "+" << result[2] << std::endl;
            int n = std::max(res.size(), std::max(result[1].size(), result[2].size()));
            printLine(n + 1);
            std::cout << " " << res << std::endl;
        }

        if (result[0] == "-") {
            std::string res = std::to_string(std::stoi(result[1]) - std::stoi(result[2]));
            std::cout << " " << result[1] << std::endl;
            std::cout << "-" << result[2] << std::endl;
            int n = std::max(res.size(), std::max(result[1].size(), result[2].size()));
            printLine(n + 1);
            std::cout << " " << res << std::endl;
        }

        if (result[0] == "*") {
            long long num1 = std::stoll(result[1]);
            long long num2 = std::stoll(result[2]);

            std::string ans = std::to_string(num1 * num2);

            std::vector<std::string> partials;

            for (int i = result[2].size() - 1; i >= 0; i--) {
                int digit = result[2][i] - '0';
                std::string part = std::to_string(num1 * digit);

                // Shift according to digit position
                part += std::string(result[2].size() - 1 - i, ' ');
                partials.push_back(part);
            }

            int width = std::max((int)ans.size(), std::max((int)result[1].size(), (int)result[2].size() + 1));

            for (const std::string &p : partials) {
                width = std::max(width, (int)p.size());
            }

            printSpace(width - result[1].size());
            std::cout << result[1] << std::endl;

            printSpace(width - result[2].size() - 1);
            std::cout << "*" << result[2] << std::endl;

            int firstLine = std::max((int)partials[0].size(), (int)result[2].size() + 1);
            printSpace(width - firstLine);
            printLine(firstLine);

            if (partials.size() == 1) {
                printSpace(width - ans.size());
                std::cout << ans << std::endl;
            } else {
                for (const std::string &p : partials) {
                    printSpace(width - p.size());
                    std::cout << p << std::endl;
                }

                printSpace(width - ans.size());
                printLine(ans.size());

                printSpace(width - ans.size());
                std::cout << ans << std::endl;
            }
        }
    }
    return 0;
}