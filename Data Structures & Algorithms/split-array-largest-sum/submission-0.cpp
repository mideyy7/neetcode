class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int lo = *std::max_element(nums.begin(), nums.end());
        int hi = std::accumulate(nums.begin(), nums.end(), 0);
        int result = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (is_valid(nums,mid,k)) {
                result = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return result;
    }

    bool is_valid(vector<int>& nums, int mid, int k) {
        int curr_sum = 0;
        int count = 1;
        for (int num : nums) {
            if (curr_sum + num > mid) {
                curr_sum = 0;
                count++;
            }
            curr_sum+= num;
        }
        return count <= k;
    }
};