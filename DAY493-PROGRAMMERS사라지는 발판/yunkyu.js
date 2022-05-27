function solution(board, aloc, bloc) {
    let answer = -1;
    const dy = [-1,1,0,0];
    const dx = [0,0,-1,1];
    const r = board.length, c = board[0].length;
    
    // 주변에 이동가능한 발판이 있는지 확인
    const check_around = (y, x) => {
        for(let i = 0; i < 4; i++){
            const ny = y + dy[i];
            const nx = x + dx[i];
            if(0 <= ny && ny < r && 0 <= nx && nx < c && board[ny][nx]) return true; 
        }
        return false;
    }
    
    const DFS = (y1, x1, y2, x2) => {
        if(!check_around(y1, x1)) return [false, 0]; // 패자일때
        if(y1 === y2 && x1 === x2) return [true, 1]; // 승자일때
        
        let isWin = false;
        let mn = 9999, mx = 0;
        board[y1][x1] = 0;
        for(let i = 0; i < 4; i++){
            const ny = y1 + dy[i];
            const nx = x1 + dx[i];
            if(ny < 0 || ny >= r || nx < 0 || nx >= c || !board[ny][nx]) continue;
            
            const [res, cnt] = DFS(y2, x2, ny, nx);
            
            if(!res) { // 승리할 수 있을 때, 최대한 빨리 승리하도록 플레이
                isWin = true;
                mn = Math.min(mn, cnt);
            }else if(!isWin) { // 승리할 수 없을 때, 최대한 오래 버티도록 플레이
                mx = Math.max(mx, cnt);
            }
        }
        board[y1][x1] = 1;
        if(isWin) return [isWin, mn + 1]; // 승리할 수 있다면 최소 횟수 반환
        else return [isWin, mx + 1]; // 패배한다면 최대 횟수 반환
    }
    
    const ret = DFS(aloc[0], aloc[1], bloc[0], bloc[1]);
    
    return answer = ret[1];
}
