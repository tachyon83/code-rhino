const BFS = (start, n, computers, visited) => {
    const queue = [start];
    visited[start] = true;
    
    while(queue.length !== 0) {
        const front =  queue.shift();
        for(let i = 0; i < n; i++) {
            if(!visited[i] && computers[front][i]) { // 연결 되어있고 방문한적이 없다면
                visited[i] = true;
                queue.push(i);
            }
        }
    }
}

function solution(n, computers) {
    let answer = 0;
    const visited = new Array(n).fill(false);
    for(let i = 0; i < n; i++){
        if(!visited[i]) { // 방문한적이 없다면 BFS로 네트워크 전체 탐색
            BFS(i,n,computers,visited);
            answer++; // 탐색한 횟수가 네트워크의 수
        }
    }
    
    return answer;
}
