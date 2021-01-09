/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    struct ListNode head;
    struct ListNode *result = &head;
    struct ListNode *p1, *p2;
    int i;
    
    head.val = -1;
    head.next = 0;
    
    if (listsSize < 1)
        return 0;
    
    p1 = lists[0];
    if (listsSize == 1) {
        head.next = lists[0];
    }
    
    for (i = 1; i < listsSize; i++) {
        p2 = lists[i];
    
        while (p1 != 0 || p2 != 0) {
            if (p1 == 0) {
                result->next = p2;
                result = result->next;
                p2 = p2->next;
                continue;
            } else if (p2 == 0) {
                result->next = p1;
                result = result->next;
                p1 = p1->next;
                continue;
            }
        
            if (p1->val < p2->val) {
                result->next = p1;
                result = result->next;
                p1 = p1->next;
            } else {
                result->next = p2;
                result = result->next;
                p2 = p2->next;
            }
        }
        
        result = &head;
        p1 = result->next;
    }
    
    result = &head;
    return result->next;
}
