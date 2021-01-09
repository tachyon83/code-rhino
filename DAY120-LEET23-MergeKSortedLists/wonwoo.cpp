class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        int size = lists.size();

        while (size > 1) {
            for (int i = 0; i < size / 2; i++) {
                lists[i] = mergeTwoLists(lists[i], lists[size - 1 - i]);
            }
            size = (size + 1) / 2;
        }

        return lists.front();
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }

        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};