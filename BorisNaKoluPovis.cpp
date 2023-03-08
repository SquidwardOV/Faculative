#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Функция для вычисления логического выражения
bool evaluate_expression(string expression, int& index) {
    if (expression[index] == '1') {
        index++;
        return true;
    } else if (expression[index] == '0') {
        index++;
        return false;
    } else if (expression[index] == '~') {
        index++;
        bool result = !evaluate_expression(expression, index);
        return result;
    } else if (expression[index] == '(') {
        index++;
        bool left_operand = evaluate_expression(expression, index);
        char operation = expression[index];
        index++;
        bool right_operand = evaluate_expression(expression, index);
        index++;
        if (operation == '+') {
            return left_operand || right_operand;
        } else {
            return left_operand && right_operand;
        }
    }
    return false;
}

int main() {
    string expression;
    ifstream input("input.txt");
    getline(input, expression);
    input.close();
    int index = 0;
    bool result = evaluate_expression(expression, index);
    cout << "Результат: " << result << endl;
    return 0;
}
