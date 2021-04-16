import java.util.*;

class Solution {
    public int solution(int[] numbers, int target) {
			int answer = 0;
			int tn = target;
			int arrLength = 0;

			for (int i = 0; i < numbers.length+2; i++) {
				arrLength += Math.pow(2, i);

			}
			
			//System.out.println("arrLength = " + arrLength);
			int arr[] = new int[arrLength + 1];
			
			arr[1] = numbers[0];
			arr[2] = numbers[0]*-1;
			//System.out.println("arr[0] = " + arr[0]);
			int i = 3; int depth = 1;
			
			int count = 1;
			while (i < arrLength) {
				if(count > Math.pow(2, depth+1)) {
					//System.out.println("====================\ncount 1로 변경 ~~~~~~ ");
					count = 1;
					depth++;
				}
				//System.out.println("\ni = "+ i + ", depth = "+ (depth) + ", count = "+count );
				
				if(i%2 == 1) {
					if(depth >= numbers.length) {
						arr[i] = arr[(int)((i-1)/2)];
						//System.out.print(arr[i] +" = "+ arr[(int)((i-1)/2)]);
						break;
					}else {
						arr[i] = arr[(int)((i-1)/2)] + numbers[depth];
						//System.out.print(arr[i]+" = "+ arr[(int)((i-1)/2)] +" + "+numbers[depth]);
					}
					
				}else {
					if(depth >= numbers.length) {
						arr[i] =  arr[(int)((i-1)/2)];
						//System.out.print(arr[i] +" = "+ arr[(int)((i-1)/2)]);
						break;
					}else {
						arr[i] =  arr[(int)((i-1)/2)] - numbers[depth];
						//System.out.print(arr[i] + " = "+ arr[(int)((i-1)/2)] +" - "+numbers[depth]);
					}
					
				}
				//System.out.println();
				count ++;
				i++;

			}
			/*
			System.out.print("\n\nk는 여기서부터 " + (int) (Math.pow(2, numbers.length)-1));
			System.out.println(" ~ " + ((int) Math.pow(2, numbers.length+1)-1)+" 여기까지");
		
			
			for(int f=(int) Math.pow(2, numbers.length)-1;
					f<(int) Math.pow(2, numbers.length+1)-1;f++) {
				System.out.print(arr[f] + " ");
				if(f%5 == 4) {
					System.out.println();
				}
				
			}
			 */
			for (int k = (int) Math.pow(2, numbers.length)-1; k < Math.pow(2, numbers.length+1)-1; k++) {
				// System.out.println("k = " + k);
				if (target == arr[k]) {
					answer++;
				}
			}
			
			return answer;
		}
}
