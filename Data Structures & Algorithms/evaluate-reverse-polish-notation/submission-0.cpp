class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::vector<int> stack;
        for (auto &operand: tokens) {
            if (operand != "+" && operand != "-" && operand != "*" && operand != "/") {
                stack.push_back(stoi(operand));
            } else {
                int operand_1 = stack.back();
                stack.pop_back();
                int operand_2 = stack.back();
                stack.pop_back();
                int result;
                if (operand == "+") {
                     result = operand_1 + operand_2;
                } else if (operand == "-") {
                    result = operand_2 - operand_1;
                } else if (operand == "*") {
                    result = operand_1 * operand_2;
                } else {
                    result = operand_2 / operand_1;
                }
                stack.push_back(result);
            }
        }
        return stack.back();
        
    }
};
