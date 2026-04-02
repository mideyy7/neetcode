class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 1:
            return strs[0]

        strs.sort()
        first = strs[0]
        second = strs[1]
        i = 0
        while i < len(first) and first[i] == second[i]:
            i += 1
        prefix = first[:i]

        for index in range(2, len(strs)):
            temp = strs[index]
            j = 0
            while j < len(prefix) and prefix[j] == temp[j]:
                j += 1
            prefix = prefix[:j]
        return prefix
        
        