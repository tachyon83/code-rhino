let parent;

// 부모 노드를 찾는다
const find = (x) => {
    if(x === parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

const union = (a, b) => {
    a = find(a);
    b = find(b);
    if(a === b) return false; // 부모가 같다면 연결 x
    parent[b] = a; // 두 노드 연결
    
    return true;
}

function solution(n, costs) {
    var answer = 0;
    parent = new Array(n);
    for(let i = 0; i < n; i++) parent[i] = i;
    costs.sort((a,b) => a[2] - b[2]); // cost 오름차순으로 정렬
    for(let i = 0; i < costs.length; i++){
        const [a,b,c] = costs[i];
        // 유니온 파인드 이용 
        if(union(a,b)) answer += c;
    }
    
    return answer;
}
