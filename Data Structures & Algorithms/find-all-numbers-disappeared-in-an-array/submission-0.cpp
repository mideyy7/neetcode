/*
Space Optimized:
- sort
- for (1 -> n): pointer at vector
- while i == vector[pointer]: increment pointer: continue
- if i != vector[i]: res.push_back(i)


*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int pointer = 0;
        vector<int> result;
        for (int i = 1; i <= nums.size(); ++i) {
            bool next = false;
            while (pointer < nums.size() && i == nums[pointer]) {
                pointer += 1;
                next = true;
            }
            if (next) continue;
            result.push_back(i);
        }
        return result;
    }
};