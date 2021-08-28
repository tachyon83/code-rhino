import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    private static boolean flag;

    private static String display(Deque<String> q, boolean direction) {
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        if(direction){ //정방향
            while(!q.isEmpty()){
                if(q.size() == 1)
                    sb.append(q.pollFirst());
                else
                    sb.append(q.pollFirst()).append(",");
            }
        }else{ //역방향
            while(!q.isEmpty()){
                if(q.size() == 1)
                    sb.append(q.pollLast());
                else
                    sb.append(q.pollLast()).append(",");
            }
        }
        sb.append("]");
        return sb.toString();
    }

    private static String convertArray(String command, Deque<String> q) {

        boolean direction = true; //true는 정방향, false는 역방향
        for(int i = 0; i < command.length(); i++){
            if(command.charAt(i) == 'R'){
                direction = !direction;
            }else{
                if(q.isEmpty()){
                    flag = true;
                    break;
                }else{
                    if(direction){
                        q.pollFirst();
                    }else{
                        q.pollLast();
                    }
                }
            }
        }
        return display(q,direction);
    }

    public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(input.readLine());
        for(int i = 0;i < n ;i++){
            String command = input.readLine();
            int indexCount = Integer.parseInt(input.readLine());
            flag = false;
            String str = input.readLine();
            String result;
            Deque<String> q = new LinkedList<>();
            if(!str.equals("[]")){
                String[] array = str.replace("[", "").replace("]", "").split(",");
                q.addAll(Arrays.asList(array));
            }
            result = convertArray(command,q);
            if(flag){
                System.out.println("error");
            }else{
                System.out.println(result);
            }
        }
    }
}
