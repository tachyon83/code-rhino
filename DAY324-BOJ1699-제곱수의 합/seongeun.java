

public class Main{

	public static void main(String[] args) throws Exception, IOException {
		BufferedReader input=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter output=new BufferedWriter(new OutputStreamWriter(System.out));
		int n=Integer.parseInt(input.readLine());
		int dp[]=new int[n+1];
		for(int i=1;i<=n;i++) //dp[i]를 정하고
		{
			dp[i]=i; //max값 을 넣는다?
			for(int j=1;j*j<=i;j++) //최소가 되는 dp[i]를 순회 하기위한 변수 j
			{
				if(dp[i-j*j]+1<dp[i])
				dp[i]=dp[i-j*j]+1;
			}
		}
		System.out.println(dp[n]);
		
		// TODO Auto-generated method stub

	}

}
