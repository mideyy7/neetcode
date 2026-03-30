class Solution {
public:
    bool isValid(string s) {
        std::map<char, char> hash_map = {
            {')', '('},
            {'}','{'},
            {']', '['},
            };
        std::stack<char> stack;

        for (char c: s) {
            if (hash_map.find(c) != hash_map.end()) {
                if (stack.empty()) return false;
                char top = stack.top();
                stack.pop();
                if (top != hash_map[c]) {
                    return false;
                }
            } else {
                stack.push(c);
            }
        }
        if (stack.empty()){
            return true;
        } else {
            return false;
        }
        
        
    }
};
