function solution(priorities, location) {
    let answer = 0;
    const n = priorities.length;
    const queue = [];
    
    // 인쇄작업 location을 i로 지정
    for(let i = 0; i < n; i++) {
        queue.push(i);
    }
    
    let cnt = 0;
    while(cnt < n) { 
        const top = priorities[0]; 
        let check = false;
        // 가장 앞에있는 문서보다 중요도가 높은 문서가 뒤에 있는지
        for(let i = 1; i < n; i++) {
            if(top < priorities[i]) {
                check = true;
                break;
             }
        }
        const x = queue.shift();
        const front = priorities.shift();
        if(check) { // 있다면 가장 앞의 문서를 뒤로
            queue.push(x);
            priorities.push(front);
        }
        else { // 없다면 인쇄
            cnt ++;
            if(x === location) { // 문서의 위치가 location이라면 반환
                answer = cnt;
                break;
            }
        }
    }
    
    return answer;
}
