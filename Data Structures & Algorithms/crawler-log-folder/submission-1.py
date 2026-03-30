class Solution:
    def minOperations(self, logs: List[str]) -> int:
        curr_step = 0
        for log in logs:
            if log == "../":
                if curr_step > 0:
                    curr_step -= 1
            elif log != "./":
                curr_step += 1
        return curr_step
        