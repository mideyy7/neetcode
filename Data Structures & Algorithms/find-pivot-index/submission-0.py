class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        prefix_sum = [0] * len(nums)
        suffix_sum = [0] * len(nums)

        prefix = 0
        for i in range(len(nums)):
            prefix_sum[i] = prefix
            prefix += nums[i]

        suffix = 0
        for i in range(len(nums) -1, -1, -1):
            suffix_sum[i] = suffix
            suffix += nums[i]
        
        for i in range(len(nums)):
            if prefix_sum[i] == suffix_sum[i]:
                return i
        return -1

        