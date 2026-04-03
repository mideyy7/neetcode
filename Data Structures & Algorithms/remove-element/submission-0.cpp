class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        int right_pointer = 0;
        int left_pointer = 0;
        while (right_pointer < nums.size()) {
            if (nums[right_pointer] == val) {
                right_pointer += 1;
            } else {
                nums[left_pointer] = nums[right_pointer];
                left_pointer += 1;
                right_pointer += 1;
            }
        }
        return left_pointer;
        
    }
};