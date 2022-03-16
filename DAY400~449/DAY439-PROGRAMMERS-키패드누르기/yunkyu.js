function solution(numbers, hand) {
    let answer = '';
    const keypad = {};
    let y = 0;
    // 키패드 값에 따른 y,x 좌표 지정
    [1,4,7,'*'].forEach((a) => {
        keypad[a] = {
            y,
            x : 0,
        }
        y++;
    });
    y = 0;
    [2,5,8,0].forEach((a) => {
        keypad[a] = {
            y,
            x : 1,
        }
        y++;
    });
    y = 0;
    [3,6,9,'#'].forEach((a) => {
        keypad[a] = {
            y,
            x : 2,
        }
        y++;
    });
    
    const getDist = (a,b) => { // 키패드에서 a와 b 사이의 거리 구한다
        return Math.abs(keypad[a].x - keypad[b].x) + Math.abs(keypad[a].y - keypad[b].y);
    }
    
    let left = '*', right = '#';
    numbers.forEach((num) => {
        if(num === 1 || num === 4 || num === 7) { // 1,4,7 일시 왼손을 이용
            answer += 'L';
            left = num;
        }
        else if( num === 3 || num === 6 || num === 9) { // 3,6,9 일시 오른손을 이용
            answer += 'R';
            right = num;
        }
        else { // 2,5,8,0 일시
            const leftDist = getDist(left,num);
            const rightDist = getDist(right,num);
            if(leftDist < rightDist) { // 왼손이 더 가까울경우
                answer += 'L';
                left = num;
            }
            else if(leftDist > rightDist) { // 오른손이 더 가까울경우
                answer += 'R';
                right = num;
            }
            else { // 거리가 같을때는 왼손잡이, 오른손잡이에 따라 결정
                if(hand === 'left') {
                    answer += 'L';
                    left = num;
                }
                else {
                    answer += 'R';
                    right = num;
                }
            }
        }
    });
    
    return answer;
}
