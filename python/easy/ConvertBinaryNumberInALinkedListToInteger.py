# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def getDecimalValue(self, head):
        """
        :type head: ListNode
        :rtype: int
        """
        if not head.next: return head.val
        curr = head.next
        acc = head.val
        while curr:
            acc = acc*2 + curr.val
            curr = curr.next
        return acc