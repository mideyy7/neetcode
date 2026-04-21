class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        t_pointer = 0
        for s_pointer in range(len(s)):
            if t_pointer < len(t) and s[s_pointer] == t[t_pointer]:
                t_pointer += 1
        return len(t) - t_pointer 
        