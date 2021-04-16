import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Main {
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		PriorityQueue<Integer> minHeap = new PriorityQueue<>(new Comparator<Integer>() {
			@Override
			public int compare(Integer o1, Integer o2) {
				return Integer.compare(o1, o2);
			}
		});	// 오름차순
		PriorityQueue<Integer> maxHeap = new PriorityQueue<>(new Comparator<Integer>() {
			@Override
			public int compare(Integer o1, Integer o2) {
				return Integer.compare(o2, o1);
			}
		});	// 내림차순
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt(br.readLine());
		int answer = -1;
		for(int n=0;n<N;n++) {
			int input = Integer.parseInt(br.readLine());
			if(maxHeap.size() > minHeap.size()) {
				minHeap.add(input);
			} else {
				maxHeap.add(input);
			}
			if(!(minHeap.isEmpty() || maxHeap.isEmpty()) && maxHeap.peek() > minHeap.peek()) {
				int max = maxHeap.poll();
				int min = minHeap.poll();
				maxHeap.add(min);
				minHeap.add(max);
			}
			
			sb.append(maxHeap.peek()).append("\n");
		}
		
		System.out.println(sb);
	}

}