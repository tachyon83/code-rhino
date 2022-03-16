function solution(board, moves) {
    let answer = 0;
    let basket = [];
    const l = board.length;
    
    let top = new Array(l).fill(-1); // 인형뽑기 기계 각 열의 가장 위에 있는 인형의 idx
    for(let i = 0; i < l; i++){
        for(let j = 0; j < l; j++){
            if(board[j][i] !== 0) { // 가장 위에 있는 인형의 위치를 찾는다.
                top[i] = j;
                break;
            }
        }
    }
    
    moves.forEach((move) => {
        const topIdx = top[move - 1];
        if(topIdx !== -1) { // 인형이 있는 열이라면
            const doll = board[topIdx][move - 1];
            if(basket[basket.length - 1] === doll) { // 바구니의 가장위에 있는 인형과 같다면
                basket.pop();
                answer+=2;
            }
            else basket.push(doll);
            top[move - 1]++; // 가장위의 인형 제거
            if(top[move - 1] >= l) top[move - 1] = -1; // 모든 인형이 제거됐다면 
        }
    })
    
    return answer;
}
