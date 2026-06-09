class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int total{0};
        solve(nums, 0, 0, total);
        return total;
    }

    void solve(vector<int>& nums, int index, int current, int& total) {
        if (index == nums.size()) {
            total += current;
            return;
        }
        current ^= nums[index];
        solve(nums, index + 1, current, total);
        current ^= nums[index];
        solve(nums, index + 1, current, total);
    }
};