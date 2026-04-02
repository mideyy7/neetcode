class Solution {
public:
    string decodeString(string &s) {
        std::vector<char> stack;
        for(char c: s) {
            if (c != ']') {
                stack.push_back(c);
            } else {
                std::string curr_string = "";
                while (!stack.empty() && stack.back() != '[') {
                    curr_string = stack.back() + curr_string;
                    stack.pop_back();
                }
                stack.pop_back();
                std::string k = "";
                while (!stack.empty() && isdigit(stack.back())) {
                    k = stack.back() + k;
                    stack.pop_back();
                }
                int n = stoi(k);
                for (int i = 1; i <= n; i++) {
                    for (char ch : curr_string) {
                        stack.push_back(ch);
                    }   
                }   
            }
        }
        std::string result = "";
        for (int i = 0; i < stack.size(); i++) {
            result += stack[i];
        }
        return result;   
    }
};