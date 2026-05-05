# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        """
        1. revese both linked lists
        2. add them
        3. reverse the result
        """
        list1 = self.reverse_list(l1)
        list2 = self.reverse_list(l2)
        total = self.add_list(list1, list2)
        return self.reverse_list(total)

    def reverse_list(self, curr: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        return prev

    def add_list(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = node = ListNode()
        carry = 0
        while list1 or list2 or carry:
            val_1 = list1.val if list1 else 0
            val_2 = list2.val if list2 else 0
            total = val_1 + val_2 + carry
            carry = total // 10
            node.next = ListNode(total % 10)
            node = node.next
            list1 = list1.next if list1 else None
            list2 = list2.next if list2 else None 
        return dummy.next


        
        