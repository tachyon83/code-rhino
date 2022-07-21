function solution(info, edges) {
    let answer = 0;
    const n = info.length;
    const graph = new Array(n).fill(0).map((i) => []);
    for(const [parent, child] of edges) {
        graph[parent].push(child);
    }
    
    const dfs = (curr, next, sheep, wolf) => {
        const nextNodes = [...next]; // 이전 노드에서 탐색 가능한 노드 배열
        const currIndex = nextNodes.indexOf(curr);
        
        if(info[curr] === 0) 
            sheep++;
        else 
            wolf++;
        
        answer = Math.max(answer, sheep);
        
        if(wolf >= sheep) return; // 늑대가 양보다 작거나 같아지면 더 이상 탐색하지 않는다.
        
        nextNodes.push(...graph[curr]); // child 노드 추가
        nextNodes.splice(currIndex, + 1); // 현재 노드는 제외
        
        for(const node of nextNodes) { // 이동가능한 노드로 탐색
            dfs(node, nextNodes , sheep, wolf);
        }
    }
    
    dfs(0, [0], 0, 0);
    
    return answer;
}
