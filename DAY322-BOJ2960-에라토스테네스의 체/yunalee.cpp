#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt = 0;
    int num = 0;
    int answer = 0;
    int next_num = 0;
    int N, K;
    cin >> N  >> K;

    queue<int> Queue;
    for(int i = 2; i <= N; i++){    // 2부터 N까지의 숫자를 큐에 입력한다
        Queue.push(i);
    }

    // K번째 순서까지 소수와 소수의 배수를 반복하여 지워간다
    while(cnt < K){
        // 지우지 않은 숫자들 중 가장 작은수를 꺼낸다
        num = Queue.front();
        Queue.pop();
        cnt++;

        if(cnt >= K){
            answer = num;
            break;
        }

        /* 현재 들어있는 숫자를 모두 반복을 통해 검사  *
         * 해당 숫자가 num의 배수인 경우 지워준다     */
        int loop_cnt = 0;
        int len = Queue.size();
        while(loop_cnt < len){
            next_num = Queue.front();
            Queue.pop();
            loop_cnt++;

            /* 다음 숫자가 최초 지워진 소수의 배수인 경우, 지운 숫자 카운트 +1    *
             * 배수가 아닌 경우, 지우지 않는다                                  */
            if(next_num%num != 0){
                Queue.push(next_num);
            }else{
                cnt++;
                if(cnt >= K){
                    answer = next_num;
                    break;
                }
            }
        }
    }

    cout << answer << '\n';

    return 0;
}
