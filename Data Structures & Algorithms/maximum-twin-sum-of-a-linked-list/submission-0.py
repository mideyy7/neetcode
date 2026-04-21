# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        elements = []
        curr = head
        max_sum = -float('inf')
        while curr:
            elements.append(curr.val)
            curr = curr.next
        left_ptr, right_ptr = 0, len(elements) - 1
        while left_ptr < right_ptr:
            max_sum = max(max_sum, elements[left_ptr] + elements[right_ptr])
            left_ptr += 1
            right_ptr -= 1
        return max_sum
        