package jiwon;

import java.io.*;
import java.util.*;

class Pair implements Comparable<Pair> {
	int index;
	int weight;

	Pair(int f, int s) {
		this.index = f;
		this.weight = s;
	}

	@Override
	public int compareTo(Pair p) {
		if (this.weight < p.weight) {
			return -1;
		} else if (this.weight == p.weight) {
			if (this.index < p.index) {
				return -1;
			}
		}
		return 1;
	}
}

public class Main {
	static boolean[][] visit;
	static int[] dist;
	static int[] dist2;
	static ArrayList<ArrayList<Pair>> arrList, reverse_arrList;
	static int v,e,x;
	static final int inf = 10000000;
	
	
	static int[] dijkstra(ArrayList<ArrayList<Pair>> a) {
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		pq.add(new Pair(x,0));
		
		boolean [] check = new boolean[v+1];
		int [] dist = new int[v+1];
		Arrays.fill(dist, inf);
		dist[x] = 0;
		
		while(!pq.isEmpty()) {
			Pair curPair = pq.poll();
			int cur = curPair.index;
			
			if(!check[cur]) {
				check[cur] = true;
				
				for(Pair pair : a.get(cur)) {
					if(!check[pair.index] && dist[pair.index] > dist[cur] + pair.weight) {
						dist[pair.index] = dist[cur] + pair.weight;
						pq.add(new Pair(pair.index, dist[pair.index]));
					}
				}
			}
			
		}
		return dist;
		
	}

	public static void main(String[] args) throws IOException {

		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		
		
		String s[] = bf.readLine().split(" ");
		v = Integer.parseInt(s[0]);
		e = Integer.parseInt(s[1]);
		x = Integer.parseInt(s[2]);

		visit = new boolean[v + 1][v + 1];
		arrList = new ArrayList<>();
		reverse_arrList = new ArrayList<>();
		
		for(int i=0;i<=v;i++) {
			arrList.add(new ArrayList<>());
			reverse_arrList.add(new ArrayList<>());
		}
		
		dist = new int[v + 1];
		dist2 = new int[v + 1];

		for (int i = 0; i <= v; i++) {
			
				dist[i] = inf;
				dist2[i] = inf;
		}

		for (int i = 0; i < e; i++) {
			String s2[] = bf.readLine().split(" ");
			int a = Integer.parseInt(s2[0]);
			int b = Integer.parseInt(s2[1]);
			int c = Integer.parseInt(s2[2]);
			arrList.get(a).add(new Pair(b,c));
			reverse_arrList.get(b).add(new Pair(a,c));
		}

		dist = dijkstra(arrList);
		dist2 = dijkstra(reverse_arrList);

		
		
		

		int max = -1;
		for (int i = 1; i <= v; i++) {
			int temp = dist[i] + dist2[i];
			if (temp > max && temp < 10000000) {
				max = dist[i] + dist2[i];
			}
		}

		System.out.println(max);
	}

}
