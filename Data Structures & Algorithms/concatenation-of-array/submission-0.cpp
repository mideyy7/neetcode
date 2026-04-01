class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        std::vector<int> result;
        for (int i = 1; i <= 2; i++) {
            for (int val: nums) {
                result.push_back(val);
            }
        }
        return result;

        
    }
};