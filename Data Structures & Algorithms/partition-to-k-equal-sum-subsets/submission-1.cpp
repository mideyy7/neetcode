class Solution {
    // Input: nums = [2,4,1,3,5], k = 3
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        vector<int> visited(nums.size(),0);
        int total = 0;
        for (int num : nums) total+=num;
        if (total % k != 0) return false;
        return solve(0, nums, k, 0, total / k, 0, visited);
    }

    bool solve(int index,vector<int>& nums, int k, int total, int target, int count, vector<int> & visited) {
        if (count == k) {
            return true;
        }
        for (int j = index; j < nums.size(); j++) {
            if (visited[j]) continue;
            if (total + nums[j] > target) continue;
            total+=nums[j];
            visited[j] = true;
            if (total == target) {
                if (solve(0, nums, k, 0, target, count + 1, visited)) return true;
            } else {
                if (solve(j + 1, nums, k, total, target, count, visited)) return true;
            };
            total-=nums[j];
            visited[j] = false;
        }
        return false;
    }
};