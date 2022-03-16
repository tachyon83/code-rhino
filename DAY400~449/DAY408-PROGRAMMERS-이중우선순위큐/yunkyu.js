function solution(operations) {
    let answer = [];
    const queue = [];
    for(let i = 0; i < operations.length; i++){
        const op = operations[i][0];
        const num = operations[i].substring(2) * 1;
        
        if(op === 'I'){ // 삽입 연산
            queue.push(num);
            queue.sort((a,b) => a - b); // 삽입후 오름차순 정렬
        }
        else { // 삭제 연산
            if(queue.length === 0) continue; // 비어있으면 무시
            if(num === 1) { // 최댓값 삭제
                queue.pop();
            } else { // 최솟값 삭제
                queue.shift();
            }
        }
    }
    
    if(queue.length > 0) { // 비어있지 않으면
        if(queue.length > 1) { // 최댓값 최솟값 둘다 존재할때
            answer.push(queue[queue.length-1]);
        }
        answer.push(queue[0]);
    }
    else answer = [0,0]; // 비어있으면
    
    return answer;
}
