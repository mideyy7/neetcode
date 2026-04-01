class Solution {
        
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector <int> stack;
        std::vector <int> result(temperatures.size(), -1);

        for (int index = temperatures.size() -1; index >= 0; index--) {
            while (!stack.empty() && temperatures[stack.back()] <= temperatures[index]) {
                stack.pop_back();
            }
            if (stack.empty()) {
                result[index] = 0;
            } else {
                result[index] = stack.back() - index;
            }
            stack.push_back(index);
        }
        return result;
    }
};
