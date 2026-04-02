class Solution {
public:
    string removeDuplicates(string s, int k) {
        /*
        1. iterate through s and push each char to stack
        2. before push check if stack is empty and if stack[-1] == current char
        3. if equan checlk if stack[-1][1] == k - 1
        4. if true: for _ in range(k - 1): pop from stack
        5. if false: append (char, stack[-1][1] + 1)
        */
        std::vector<std::pair<char, int>> stack;
        for(char c: s) {
            if (!stack.empty() and stack.back().first == c) {
                int n = stack.back().second;
                if (n == k - 1) {
                    for (int i = 0; i < n; i++) {
                        stack.pop_back();
                    }
                } else {
                    stack.push_back({c,n + 1});
                }
            } else {
                stack.push_back({c,1});
            }
        }
        std::string result = "";
        for (auto temp: stack) {
            result += temp.first;
        }
        return result; 
    }
};