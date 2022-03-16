import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main{

	public static void main(String[] args) throws Exception{
		StringBuilder sb=new StringBuilder();
		BufferedReader input=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(input.readLine());
		for(int z=1;z<=t;z++)
		{
			int n=Integer.parseInt(input.readLine());
			int arr[]=new int[n+1];
			int sum[]=new int[n+1];
			int dp[][]=new int[n+1][n+1];
			StringTokenizer st=new StringTokenizer(input.readLine());
			for(int i=1;i<=n;i++)
			{
				arr[i]=Integer.parseInt(st.nextToken());
				sum[i]=(sum[i-1]+arr[i]); //이걸 사용하는것이 핵심이다.
			}
			for(int i=1;i<n;i++) //i+1 구간 크기를 정한다
			{
				for(int j=1;j+i<=n;j++) //dp[j][]
				{
					dp[j][j+i]=Integer.MAX_VALUE;
					for(int mid=j;mid<j+i;mid++) //구간이 3이상일때 짤라서 제일 작은 값이 되는 구간을 찾는다
					{
						dp[j][j+i]=Math.min(dp[j][j+i],dp[j][mid]+dp[mid+1][j+i]);
					}
					dp[j][j+i]+=(sum[j+i]-sum[j-1]);
					//sb.append(j+" "+(j+i)+" "+dp[j][j+i]+"\n");
				}
			}
			sb.append(dp[1][n]+"\n");
			
		}
		System.out.println(sb);
		// TODO Auto-generated method stub

	}

}
