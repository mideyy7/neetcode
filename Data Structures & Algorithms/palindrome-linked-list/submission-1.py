# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        # find mid point
        # reverse second half
        # check if they are equal

        slow = head
        fast = head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        prev = None
        while slow:
            temp = slow.next
            slow.next = prev
            prev = slow
            slow = temp
        
        first = head
        second = prev
        while first:
            if first.val != second.val:
                return False
            first = first.next
            second = second.next
        return True
   
      

        
        """

        1 -> 2 -> 3 -> 4 -> Null

        1 -> 2 -> 3 -> Null

        """
        