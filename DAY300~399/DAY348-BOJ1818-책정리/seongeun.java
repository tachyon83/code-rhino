package DataStructure.BinarySearch;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

/*
5
2 1 4 5 3
 */
public class 책정리_1818 {

    public static void main(String[] args) throws Exception{

        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(input.readLine());
        ArrayList<Integer> list = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(input.readLine());

        for(int i = 0; i < n; i++) {
            int value = Integer.parseInt(st.nextToken());
            int start = 0;
            int end = list.size() - 1;
            if(list.get(end) < value) {
                list.add(value);
            } else {

                while(start < end) {
                    int mid = ( start + end) / 2;
                    if(list.get(mid) < value) {
                        start = mid + 1;
                    } else {
                        end = mid;
                    }
                }
                list.set(end, value);
            }
        }
        System.out.println(n - (list.size() - 1));
    }
}

