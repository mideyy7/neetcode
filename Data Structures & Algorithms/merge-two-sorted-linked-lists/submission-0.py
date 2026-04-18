# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1:
            return list2
        elif not list2:
            return list1
        else:
            curr_A, curr_B = list1, list2
            dummy = dummy_node = ListNode()
            while curr_A and curr_B:
                if curr_A.val < curr_B.val:
                    dummy.next = curr_A
                    curr_A = curr_A.next
                else:
                    dummy.next = curr_B
                    curr_B = curr_B.next
                dummy = dummy.next
            if curr_A:
                dummy.next = curr_A
            if curr_B:
                dummy.next = curr_B
            return dummy_node.next
            