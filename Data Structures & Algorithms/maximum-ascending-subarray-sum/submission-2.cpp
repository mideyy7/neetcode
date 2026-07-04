class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int max_sum = 0;
        int curr_sum = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (right == 0) {
                curr_sum += nums[right];
                max_sum = std::max(max_sum, curr_sum);
                continue;
            }
            if (nums[right] > nums[right -1]) {
                curr_sum += nums[right];
                max_sum = std::max(max_sum, curr_sum);
            } else {
                curr_sum = nums[right];
            }
        }
        return max_sum; 
    }
};