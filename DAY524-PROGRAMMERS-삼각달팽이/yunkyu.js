function solution(n) {
    const answer = [];
    
    const arr = Array.from(Array(n), () => new Array(n).fill(0)); // 삼각으로 숫자를 채울 2차원 배열
    
    let cnt = 1;
    let cy = -1, cx = 0;
    let turn = 0;
    for(let i = n; i >= 1; i--){
        // n -> (n - 1) -> ... -> 1 순으로 반시계 방향 채우기
        for(let j = 0; j < i; j++){
            // 아래 -> 오른쪽 -> 위 순서에 따른 좌표 변경
            if(turn % 3 === 0){
                cy++;
            }
            else if(turn % 3 === 1){
                cx++;
            }
            else {
                cy--;
                cx--;
            }
            arr[cy][cx] = cnt++;
        }
        turn++;
    }
    
    for(let i = 0; i < n; i++){
        for(let j = 0; j < i + 1; j++){
            answer.push(arr[i][j]);
        }
    }
    
    return answer;
}
