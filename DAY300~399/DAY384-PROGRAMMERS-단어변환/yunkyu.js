// 두 단어의 차이가 문자 한개인지 확인하는 함수
const check = (s1, s2) => {
    let cnt = 0;
    for(let i = 0; i < s1.length; i++){
        if(s1[i] !== s2[i]) cnt++;
    }
    
    if(cnt === 1) return true;
    else return false;
}

const BFS = (begin,target) => {
    const q = [{
        word:begin,
        cnt:0,
    }]
    
    while(q.length !== 0){
        const curr = q[0].word;
        const cnt = q[0].cnt;
        q.shift();
        
        if(curr === target) return cnt; // target이 되었다면 변환 횟수 반환
        
        for(let i = 0; i < adj[curr].length; i++){
            if(!visited[adj[curr][i]]){ // 변환했던 단어가 아니라면
                visited[adj[curr][i]] = true;
                q.push({
                    word:adj[curr][i],
                    cnt: cnt + 1,
                })
            }
        }
    }
}

// 단어간 adjacency list 를 만든다
const setAdj = (word, words) => {
    for(let i = 0; i < words.length; i++){
        if(words[i] !== word){
            if(check(words[i],word)) {
                adj[word].push(words[i]);
            }
        }
    }
}

const visited = {}, adj = {};

function solution(begin, target, words) {
    var answer = 0;
    let flag = false;
    // target단어가 words에 있는지 확인
    for(let i = 0; i < words.length; i++){
        if(words[i] === target) flag = true;
    }
    
    if(flag){ 
        adj[begin] = [];
        // adjacency list , visited 배열 초기화
        for(let i = 0; i < words.length; i++) {
            visited[words[i]] = false;
            adj[words[i]] = [];
        }
        
        setAdj(begin, words);
        for(let i = 0; i < words.length; i++)
            setAdj(words[i],words);
        
        answer = BFS(begin,target);
    }
    
    return answer;
}
