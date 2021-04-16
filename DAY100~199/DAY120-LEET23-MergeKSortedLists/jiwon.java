/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
      PriorityQueue<Integer> pq = new PriorityQueue<>(); 
        
       for(ListNode list : lists){
           while(list != null){
               pq.add(list.val);
               list = list.next;
           }
       }
        
        ListNode first = new ListNode(-1);
        ListNode now = first;
        
        while(!pq.isEmpty())
        {
            now.next = new ListNode(pq.poll());
            now = now.next;
        }        
        
      

        return first.next;
    }
}