class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        right_pointer = 0
        max_sum = curr_sum = nums[0]
        for right_pointer in range(1, len(nums)):
            if nums[right_pointer] > nums[right_pointer - 1]:
                curr_sum += nums[right_pointer]
                right_pointer += 1
            else:
                max_sum = max(max_sum, curr_sum)
                curr_sum = nums[right_pointer]

        max_sum = max(max_sum, curr_sum)
        return max_sum
            
            