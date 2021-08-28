import java.util.*;
import java.io.*;
 
class Main {
    static int stoi(String s) { return Integer.parseInt(s);}
 
    static long swapCount = 0;
    static long[] sorted;
 
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
 
        int n = stoi(br.readLine());
        sorted = new long[n];
        long[] arr = new long[n];
 
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++)
            arr[i] = stoi(st.nextToken());
 
        mergeSort(arr, 0, n-1);
        
        System.out.println(swapCount);
    }
 
    static void mergeSort(long[] arr, int low, int high) {
        if(low < high) {
            int mid = (low+high)/2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid+1, high);
            merge(arr, low, mid, high);
        }
    }
 
    static void merge(long[] arr, int low, int mid, int high) {
        int i = low;
        int j = mid + 1;
        int index = low;
 
        while(i <= mid && j <= high) {
            if(arr[i] <= arr[j])
                sorted[index++] = arr[i++];
            else {
                sorted[index++] = arr[j++];
                swapCount += (mid + 1 - i);
            }
        }
 
        while(i <= mid) 
            sorted[index++] = arr[i++];
        
        while(j <= high)
            sorted[index++] = arr[j++];
 
        for(int k=low; k<=high; k++)
            arr[k] = sorted[k];
    }
}
