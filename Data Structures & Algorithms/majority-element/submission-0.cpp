class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0;
        int count = 0;
        for (int num : nums) {
            if (count == 0) {
                res = num;
            }
            if (num == res) {
                count += 1;
            } else {
                count -= 1;
            }
        }
        return res;     
    }
};