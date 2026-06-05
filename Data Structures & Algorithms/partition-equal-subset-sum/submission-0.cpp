class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int num: nums) {
            total += num;
        }
        if (total % 2 != 0) return false;
        return solve(nums, total / 2, 0);       
    }

    bool solve(vector<int>& nums, int target, int index) {
        if (index >= nums.size()) {
            return (target == 0);
        }
        if (target < 0) return false;
        bool pick = solve(nums, target - nums[index], index + 1);
        bool not_pick = solve(nums, target, index + 1);
        return pick || not_pick;
    }
};
