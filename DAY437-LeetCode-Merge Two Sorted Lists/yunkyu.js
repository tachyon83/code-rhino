/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeTwoLists = function(list1, list2) {
    if(!list1) return list2; // list1에 더 이상 노드가 없을 경우 list2를 반환
    if(!list2) return list1; // list2에 더 이상 노드가 없을 경우 list1를 반환
    
    if(list1.val < list2.val) { // list1의 노드값이 list2의 노드값보다 작을경우
        list1.next = mergeTwoLists(list1.next,list2);
        return list1;
    }
    else { // list1의 노드값이 list2의 노드값보다 작거나 클 경우
        list2.next = mergeTwoLists(list1,list2.next);
        return list2;
    }
};
