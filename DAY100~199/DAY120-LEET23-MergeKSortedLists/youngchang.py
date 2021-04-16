class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        def mergeTwoLists(l1, l2):
            dummy = cur = ListNode(0)
            while l1 and l2:
                if l1.val < l2.val:
                    cur.next = l1
                    l1 = l1.next
                else:
                    cur.next = l2
                    l2 = l2.next
                cur = cur.next
            cur.next = l1 or l2
            return dummy.next
        
        if lists == None:
            return None
        
        N = len(lists)
        mid = N // 2
        
        if N == 1:
            return lists[0]
        
        top, bottom = None, None
        if mid > 0:
            top = self.mergeKLists(lists[:mid])
        if mid <= N-1:
            bottom = self.mergeKLists(lists[mid:])
        
        return mergeTwoLists(top, bottom)