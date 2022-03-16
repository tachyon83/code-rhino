
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
 
public class Main {
    static int N,M,K;
    static int arr[][], map[][];
    static int moveX[] = {0,1,1,1,0,-1,-1,-1};
    static int moveY[] = {-1,-1,0,1,1,1,0,-1};
    static ArrayList<Integer> arrList[][];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        
        arr = new int[N+1][N+1];
        map = new int[N+1][N+1];
        
        arrList = new ArrayList[N+1][N+1];
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
                arrList[i][j] = new ArrayList<>();
        
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++)
                map[i][j] = 5;
        }
        for(int i=1; i<=N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=1; j<=N; j++) 
                arr[i][j] = Integer.parseInt(st.nextToken());
                
        }
        for(int m=1; m<=M; m++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int age = Integer.parseInt(st.nextToken());
            arrList[u][v].add(age);
        }
        int k = 0;
        while(k<K) {
            
            for(int i=1; i<=N; i++) {
                for(int j=1; j<=N; j++) {
                    if(arrList[i][j].size() > 0) {
                        int end = 0;
                        Collections.sort(arrList[i][j]);
                        
                        ArrayList<Integer> tmp = new ArrayList<>();
                        for(int q=0; q<arrList[i][j].size(); q++) {
                            int age = arrList[i][j].get(q);
                            if(map[i][j] >= age) {
                                map[i][j] -= age;
                                tmp.add(age+1);
                            }else {
                                end += age/2;
                            }
                        }
                        arrList[i][j] = new ArrayList<>();
                        for(int val : tmp)
                            arrList[i][j].add(val);
                        
                        map[i][j] += end;
                    }
                }
            }
            
            for(int i=1; i<=N; i++) {
                for(int j=1; j<=N; j++) {
                    if(arrList[i][j].size() > 0) {
                        
                        for(int q=0; q<arrList[i][j].size(); q++) {
                            int age = arrList[i][j].get(q);
                            if(age % 5 == 0) {
                                for(int d=0; d<8; d++) {
                                    int newX = j + moveX[d];
                                    int newY = i + moveY[d];
                                    if(0<newX && newX<=N && 0<newY && newY<=N) {
                                        arrList[newY][newX].add(1);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            
            for(int i=1; i<=N; i++)
                for(int j=1; j<=N; j++)
                    map[i][j] += arr[i][j];
       
            k++;
        }
        int result = 0;
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                result += arrList[i][j].size();
            }
        }
        System.out.println(result);
    }
}
    
 
