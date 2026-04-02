class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 1:
            return strs[0]

        strs.sort()
        prefix = strs[0]
        for index in range(1, len(strs)):
            temp = strs[index]
            j = 0
            while j < len(prefix) and prefix[j] == temp[j]:
                j += 1
            prefix = prefix[:j]
        return prefix
        
        