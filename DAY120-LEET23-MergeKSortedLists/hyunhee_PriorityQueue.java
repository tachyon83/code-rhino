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
			PriorityQueue<ListNode> pq = new PriorityQueue<>(new Comparator<ListNode>() {

				@Override
				public int compare(ListNode o1, ListNode o2) {
					return o1.val - o2.val;
				}
				
			});
			
			for(ListNode node : lists) {
				while(node!=null) {
					pq.add(node);
                    node = node.next;
				}
			}
        
			ListNode answer = new ListNode(0);
            ListNode next = answer;
			while(!pq.isEmpty()) {
				next.next = new ListNode();
				next = next.next;
				next.val = pq.poll().val;
			}
			
			return answer.next;
		}
}