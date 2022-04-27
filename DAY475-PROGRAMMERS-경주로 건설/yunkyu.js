// 25번 케이스만 실패. 해결해야 함

function solution(board) {
    let answer = 987654321;
    const dy = [0,0,-1,1];
    const dx = [1,-1,0,0];
    const n = board.length;
    const visited = Array.from(Array(n), () => Array(n).fill(0));
    
    const bfs = (y, x, dir, cost) => {
        const q = [];
        q.push([y, x, dir, cost])
        
        while(q.length) {
            const front = q.shift();
            const [y, x, dir, cost] = front;
            
            if(y === n - 1 && x === n - 1) {
                answer = Math.min(answer, cost);
                continue;
            }
            
            for(let i = 0; i < 4; i++){
                const ny = y + dy[i];
                const nx = x + dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >= n || board[ny][nx]) continue;
                
                let ncost = cost;
                if(dir === i || dir === -1) ncost += 100;
                else ncost += 600;
                if(!visited[ny][nx]|| visited[ny][nx] >= ncost) {
                    visited[ny][nx] = ncost;
                    q.push([ny, nx, i, ncost]);
                }
            }
        }
    }
    
    bfs(0, 0, -1, 0);
    
    return answer;
}
