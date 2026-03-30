class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> my_stack;
        for (auto &log: logs) {
            if (log == "../") {
                if (!my_stack.empty()) {
                    my_stack.pop();
                }
            } else if (log != "./") {
                my_stack.push(log);
            }
        }
        return my_stack.size();
    }
};