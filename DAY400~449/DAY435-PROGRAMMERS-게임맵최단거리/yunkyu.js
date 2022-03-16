function solution(maps) {
    let answer = 0;
    const visited = Array.from(maps, a => new Array(a.length).fill(false)); 
    const n = maps.length - 1, m = maps[0].length - 1;
    const dy = [-1,1,0,0], dx = [0,0,-1,1];
    
    const bfs = (y,x) => { // BFS 사용
        const q = [];
        visited[y][x] = true;
        q.push([y,x,1]); // 초기 시점
        
        while(q.length) { // 큐가 비어있지 않을경우
            const [y,x,dist] = q[0];
            q.shift();
            
            if(x === m && y === n) { // 목표지점에 도착하면 바로 반환
                return dist;
            }
            
            for(let i = 0; i < 4; i++) {
                const ny = y + dy[i];
                const nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny > n || nx > m) continue; // 유효하지 않은 범위일때
                if(!visited[ny][nx] && maps[ny][nx] !== 0) { // 방문하지 않았고 벽이 아니라면 진출
                    visited[ny][nx] = true;
                    q.push([ny,nx,dist + 1]);
                }
            }
        }
        
        return 0; // 목표지점에 도착하지 못했을때
    }
    
    answer = bfs(0,0);
    if(answer === 0) answer = -1;

    return answer;
}
