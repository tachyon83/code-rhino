function solution(N, number) {
    let answer = -1;
    
    const sets = [new Set()];
    for(let i = 1; i <= 8; i++){
        const set = new Set();
        set.add(new Array(i).fill(N).join('') * 1); // NN형태 삽입
        
        for(let j = 1; j < i; j++) {
            // 합이 i개 가 되는 j와 i - j의 set 값에 대해 사칙연산한 결과를 삽입
            for(const item of sets[j]) {
                for(const item2 of sets[i - j]){
                    set.add(item + item2);
                    set.add(item - item2);
                    set.add(item * item2);
                    if(item != 0) set.add(Math.floor(item / item2));
                }
            }   
        }
        sets.push(set);
        
        if(sets[i].has(number)) { // number 표현 가능할 시 
            answer = i;
            break;
        }
    }
    
    return answer;
}
