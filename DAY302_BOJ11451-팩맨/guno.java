import java.io.*;
import java.util.*;

public class Main {

	static int m,n;
	static char[][] map;
	static int[] dx={-1,1,0,0};
	static int[] dy={0,0,1,-1};
	static char[] direction={'N','S','E','W'};
	static boolean[][][][] visited;
	static class Node{
		int x1,y1,x2,y2;
		String s="";
		Node(int x1,int y1,int x2,int y2,String s){
			this.x1=x1;this.y1=y1;this.x2=x2;this.y2=y2;this.s=s;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb=new StringBuilder();

		StringTokenizer st;
		int T=Integer.parseInt(br.readLine());
		while (T-->0){
			st=new StringTokenizer(br.readLine());
			m=Integer.parseInt(st.nextToken());
			n=Integer.parseInt(st.nextToken());
			map=new char[m][n];
			visited=new boolean[m][n][m][n];
			int[] pPoints={-1,-1,-1,-1,0};

			for (int i = 0; i < m; i++) {
				String temp=br.readLine();
				for (int j = 0; j < n; j++) {
					char c=temp.charAt(j);
					if(c=='P'){
						if(pPoints[0]!=-1){
							pPoints[2]=i;pPoints[3]=j;
						}
						else {
							pPoints[0] = i;
							pPoints[1] = j;
						}
					}
					map[i][j]=c;
				}
			}
			Queue<Node> q=new LinkedList<>();
			q.add(new Node(pPoints[0],pPoints[1],pPoints[2],pPoints[3],""));

			boolean isPossible=false;

			while (!q.isEmpty()){
				Node tempNode=q.poll();
				int x1=tempNode.x1,y1=tempNode.y1,x2=tempNode.x2,y2=tempNode.y2;
				String s=tempNode.s;
				if (x1==x2 && y1==y2){
					sb.append(s.length()).append(" ").append(s).append("\n");
					isPossible=true;
					break;
				}

				for (int i = 0; i < 4; i++) {
					int[] nextPoints=move(tempNode,i);
					int nx1=nextPoints[0],ny1=nextPoints[1],nx2=nextPoints[2],ny2=nextPoints[3];
					if(map[nx1][ny1]=='X'){
						nx1=x1;ny1=y1;
					}else if(map[nx1][ny1]=='G')
						continue;
					if(map[nx2][ny2]=='X'){
						nx2=x2;ny2=y2;
					}else if(map[nx2][ny2]=='G')
						continue;

					if(visited[nx1][ny1][nx2][ny2])
						continue;
					else
						visited[nx1][ny1][nx2][ny2]=true;


					q.add(new Node(nx1,ny1,nx2,ny2,s+direction[i]));
				}
			}
			if(!isPossible)
				sb.append("IMPOSSIBLE\n");
		}
		System.out.print(sb);

	}
	static int[] move(Node tempNode,int i){
		int x1=tempNode.x1,y1=tempNode.y1,x2=tempNode.x2,y2=tempNode.y2;
		int nx1=x1+dx[i],ny1=y1+dy[i],nx2=x2+dx[i],ny2=y2+dy[i];
		if(nx1<0)nx1=m-1;
		if(nx2<0)nx2=m-1;
		if(ny1<0)ny1=n-1;
		if(ny2<0)ny2=n-1;
		if(nx1==m)nx1=0;
		if(nx2==m)nx2=0;
		if(ny1==n)ny1=0;
		if(ny2==n)ny2=0;
		return new int[]{nx1,ny1,nx2,ny2};
	}

}
