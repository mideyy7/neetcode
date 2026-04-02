class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count = 0;
        int count = 0;
        for (int num: nums) {
            if (num == 1) {
                count += 1;
            } else {
                max_count = max(max_count, count);
                count = 0;
            }
        }
        max_count = max(max_count, count);
        return max_count;    
    
    }
};