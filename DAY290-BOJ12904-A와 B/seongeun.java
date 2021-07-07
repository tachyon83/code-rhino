

/*
B
ABBA
문자열의 뒤에 A를 추가한다.
문자열을 뒤집고 뒤에 B를 추가한다.
 */
public class A와B_12904 {
    private static int result = 0;
    private static int getMakeString(StringBuilder str1, StringBuilder str2) {

        for(int i = str2.length() - 1; i >= 0; i--){
            char ch = str2.charAt(i);
            str2.delete(i,str2.length());
            if( ch == 'B') str2.reverse();
            if( str2.toString().equals(str1.toString())) return 1;
        }
        return 0;
    }

    public static void main(String[] args) throws Exception{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder str1 = new StringBuilder(input.readLine());
        StringBuilder str2 = new StringBuilder(input.readLine());
        System.out.println(getMakeString(str1,str2));
    }
}
