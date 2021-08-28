import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	static int arr[];
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String input ="";
		
		arr = new int[10001];
		int idx = 0;
		while( (input = br.readLine()) != null&& input.length() !=0) {
			arr[idx++] = Integer.parseInt(input);
		}
		

		search(0, idx);

		
	}
	
	
	public static void search(int leftIdx,int rightIdx) {
		if(leftIdx >=rightIdx) return;
		
		int  newright = rightIdx;
		for(int i = leftIdx ; i <rightIdx;i++) {
			if(arr[leftIdx] < arr[i]) {
				newright = i;
				break;
			}
		}
		
		search(leftIdx+1, newright);
		search(newright, rightIdx);
		System.out.println(arr[leftIdx]);
		
	}
	
}
