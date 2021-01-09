
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        temp=[]
        for l in lists:
            curr=copy.deepcopy(l)
            while curr.next:
                temp.append(curr.val)
                curr=curr.next
            temp.append(curr.val)
        temp.sort()
        sz=len(temp)

        nLN=ListNode()
        node=nLN

        for i,e in enumerate(temp):
            node.val=e
            if(i<sz-1):
                node.next=ListNode()
                node=node.next

        return nLN
