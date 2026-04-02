class Solution:
    def simplifyPath(self, path: str) -> str:
        """
        1. parse and get operand
        2. perform operation
        a. . -> continue
        b. .. -> pop from stack
        c. else -> append to tsack
        """
        stack = []
        start = end = 0
        n = len(path)
        while end < n:
            while start < n and path[start] == "/":
                start += 1
            if start == end:
                break
            end = start
            while end < n and path[end] != "/":
                end += 1
            operand = path[start:end]
            start = end
            if operand == ".":
                continue
            elif operand == "..":
                if stack:
                    stack.pop()
            else:
                if operand:
                    stack.append(operand)
        if not stack:
            return "/"
        result = ""
        for val in stack:
            result = result + "/" + val 
        return result

        