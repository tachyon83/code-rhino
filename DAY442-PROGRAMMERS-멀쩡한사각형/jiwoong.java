import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;


public class jiwoong {

    class Solution {
        public long solution(int w, int h) {
            long answer = 0;
            for(int i = 0; i < w; i++)
                answer += (Long.valueOf(h) * i) / Long.valueOf(w);
            return 2*answer;
        }
    }
}