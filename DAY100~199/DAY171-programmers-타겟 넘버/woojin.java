// 43165번 타겟 넘버

public class PG_43165 {
    public static int answer = 0;
    public static int solution(int[] numbers, int target){

        dfs(numbers, target, numbers[0], 1);
        dfs(numbers, target, -numbers[0], 1);

        return answer;
    }

    public static void dfs(int[] numbers, int target, int current, int index){
        if(index == numbers.length) {
            if(current == target)
                answer++;
        }

        int nextIndex = index + 1;
        if(nextIndex <= numbers.length){
            dfs(numbers, target, current+numbers[index], nextIndex);
            dfs(numbers, target, current-numbers[index], nextIndex);
        }
    }

    public static void main(String[] args) {
        int[] arr = {1,1,1,1,1};

        System.out.println(solution(arr, 3));
    }
}
