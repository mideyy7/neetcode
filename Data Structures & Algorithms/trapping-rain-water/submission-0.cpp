class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int left_max = height[left], right_max = height[right];
        int result = 0;
        while (left <= right) {
            if (left_max < right_max) {
                result += std::max(0, left_max - height[left]);
                left_max = std::max(left_max, height[left]);
                left++;
            } else {
                result += std::max(0, right_max - height[right]);
                right_max = std::max(right_max, height[right]);
                right--;
            }
        }
        return result;
        
    }
};
