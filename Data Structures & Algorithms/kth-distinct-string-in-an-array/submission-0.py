class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        distinct_array = Counter(arr)
        count = 0
        for element in arr:
            if distinct_array[element] == 1:
                count += 1
            if count == k:
                return element
        return ""
            
        