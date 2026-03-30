class Solution {
public:
    int calPoints(vector<string>& operations) {
        int total = 0;
        stack<int> my_stack;

        for (auto &operation: operations) {
            if (operation == "+") {
                int top = my_stack.top();
                my_stack.pop();
                int new_top = my_stack.top() + top;
                my_stack.push(top);
                my_stack.push(new_top);
                total += new_top;
            } else if (operation == "D") {
                my_stack.push(2 * my_stack.top());
                total += my_stack.top();
            } else if (operation == "C") {
                total -= my_stack.top();
                my_stack.pop();
            } else {
                my_stack.push(stoi(operation));
                total += my_stack.top();
            }
        }
        return total;
        
    }
};