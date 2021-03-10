#include <string>
#include <vector>
using namespace std;

int answer = 0;
int len;
void dfs(int cnt, vector<int> numbers, int target, int result){
    if(len == cnt){
        if(target == result){
            answer++;
        }
        return;
    }
    
    dfs(cnt+1, numbers, target, result + numbers[cnt]);
    dfs(cnt+1, numbers, target, result - numbers[cnt]);
    
}

int solution(vector<int> numbers, int target) {
    len = numbers.size();
    
    dfs(0, numbers, target, 0);
    
    return answer;
}
