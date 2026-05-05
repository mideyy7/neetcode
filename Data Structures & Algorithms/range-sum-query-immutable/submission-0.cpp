/*
    Get prefix sum of all value before a particular point(inclusive)
    sum(right) - sum(left) + nums[left]
*/




class NumArray {
private:
    vector<int> nums;
    vector<int> prefix_sum;
public:
    NumArray(vector<int>& nums) : nums(nums) {
        int prefix = 0;
        for (int num: nums) {
            prefix += num;
            prefix_sum.push_back(prefix);
        } 
    }
    
    int sumRange(int left, int right) {
        return prefix_sum[right] - prefix_sum[left] + nums[left];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */