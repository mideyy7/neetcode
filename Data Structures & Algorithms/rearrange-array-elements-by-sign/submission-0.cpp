class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        /*
        3 pointers -> pos, neg, curr
        if 
        */
        std::vector<int> result(nums.size());
        int pos = 0, neg = 1;
        int curr = 0;
        while (curr < nums.size()) {
            if (nums[curr] >= 0) {
                result[pos] = nums[curr];
                pos += 2;
            } else {
                result[neg] = nums[curr];
                neg += 2;
            }
            curr++;
        }
        return result;
       
        
    }
};