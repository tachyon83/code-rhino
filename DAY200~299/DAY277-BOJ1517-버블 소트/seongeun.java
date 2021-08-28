public class 버블소트_1517 {

    private static int[] sorted;
    private static long count;

    private static void merge(int[] arr, int left, int mid, int right) {

        int l = left;
        int r = mid + 1;
        int idx = left;

        //sorted에 하나씩 채우기
        while(l <= mid && r <= right){
            if(arr[l] <= arr[r]){
                sorted[idx++] = arr[l++];
            }else{
                //이때가 스왑 포인트
                sorted[idx++] = arr[r++];
                count += (long)mid + 1 - l;
            }
        }

        //남은 값들 채우기
        if(l > mid){
            for(int i = r; i <= right ; i++) sorted[idx++] = arr[i];
        }else{
            for(int i = l; i <= mid ; i++) sorted[idx++] = arr[i];
        }

        for(int i = left; i <= right; i++) arr[i] = sorted[i];

    }

    private static void mergeSort(int[] arr, int left, int right) {

        if(left < right){
            int mid = (left + right) / 2;
            //왼쪽 분할
            mergeSort(arr, left, mid);
            //오른쪽 분할
            mergeSort(arr,mid + 1, right);
            //merge
            merge(arr, left, mid, right);
        }
    }

    public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());
        int[] arr = new int[n];
        sorted = new int[n];
        StringTokenizer st = new StringTokenizer(input.readLine());
        for(int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        mergeSort(arr,0,n - 1);
        System.out.println(count);
    }
}
