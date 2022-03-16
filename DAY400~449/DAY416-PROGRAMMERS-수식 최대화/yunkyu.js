const setPriority = (visited,arr,priority,num,exp) => {
    if(priority.length === arr.length) { // 연산자 우선순위를 정했다면
        // num , exp 복사
        const n = num.slice();
        const e = exp.slice();
        for(const p of priority){
            for(let i = 0; i < n.length; i++){
                for(let j = 0; j < e.length; j++){
                    if(e[j] === p) { // 현재 연산자에 해당시
                        if(e[j] === '+'){
                            n[j] += n[j + 1];
                        }else if(e[j] === '*'){
                            n[j] *= n[j + 1];
                        }else if(e[j] === '-'){
                            n[j] -= n[j + 1];
                        }
                        // 사용한 연산자와 숫자 제거 
                        e.splice(j,1);
                        n.splice(j + 1,1);
                        j--;
                    }
                }
            }
        }
        return Math.abs(n[0]); // 절댓값 반환
    }
    
    let ret = 0;
    for(let i = 0; i < arr.length; i++){
        if(visited[i]) continue; // 사용한 연산자는 pass
        visited[i] = true;
        ret = Math.max(ret,setPriority(visited,arr,[...priority,arr[i]],num,exp)); // 가장 큰 값으로 갱신
        visited[i] = false;
    }
    
    return ret;
}

function solution(expression) {
    let answer = 0;
    // 정규 표현식을 이용해 expression에서 숫자와 연산자 추출
    const num = expression.split(/\+|-|\*/).map(a => parseInt(a));
    const exp = expression.split(/[0-9]?[0-9]?[0-9]/).filter(Boolean);
    
    const arr = []; 
    
    // arr에 연산자 중복없이 push
    for(let i = 0; i < exp.length; i++){
        if(!arr.find((a) => a === exp[i])){
            arr.push(exp[i]);
        }
    }
    
    const visited = new Array(arr.length).fill(false);
    answer = setPriority(visited,arr,[],num,exp);
    
    return answer;
}
