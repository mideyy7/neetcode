class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mmax = nums[0];
        int mmin = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];
            int min_value = min({mmax * num, num, mmin * num});
            int max_value = max({mmin * num, num, mmax * num});
            mmin = min_value;
            mmax = max_value;
        result = max(result, mmax);

        }
        return result;
    }
};
