import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main{

	public static void main(String[] args) throws Exception {
		BufferedReader input=new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb=new StringBuilder();
		long total=0;
		ArrayList<Integer> list1=new ArrayList<Integer>();
		ArrayList<Integer> list2=new ArrayList<Integer>();
		int t=Integer.parseInt(input.readLine());
		int n=Integer.parseInt(input.readLine());
		int arr1[]=new int[n+1];
		StringTokenizer st=new StringTokenizer(input.readLine());
		for(int i=1;i<=n;i++)
			arr1[i]=Integer.parseInt(st.nextToken());
		int m=Integer.parseInt(input.readLine());
		int arr2[]=new int[m+1];
		st=new StringTokenizer(input.readLine());
		for(int i=1;i<=m;i++)
			arr2[i]=Integer.parseInt(st.nextToken());
		
		for(int i=1;i<=n;i++)
		{
			int sum=0;
			for(int j=i;j<=n;j++)
			{
				sum+=arr1[j];
				list1.add(sum);
			}
		}
		
		for(int i=1;i<=m;i++)
		{
			int sum=0;
			for(int j=i;j<=m;j++)
			{
				sum+=arr2[j];
				list2.add(sum);
			}
		}
		
		Map<Integer,Integer> map=new HashMap<Integer, Integer>();
		for(int num:list1)
		{
			if(map.containsKey(num))
			{
				map.put(num, map.get(num)+1);
			}
			else
			{
				map.put(num, 1);
			}
		}
		
		for(int num:list2)
		{
			if(map.containsKey(t-num))
			{
				total+=map.get(t-num);
			}
		}
		System.out.println(total);
		// TODO Auto-generated method stub

	}

}
