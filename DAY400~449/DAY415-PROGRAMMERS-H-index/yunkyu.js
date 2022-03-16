function solution(citations) {
    let answer = 0;
    
    citations.sort((a,b) => b - a); // 내림차순 정렬
    for(let i = 0; i < citations.length; i++){
        const c = citations[i];
        const to = i === citations.length - 1 ? 0 : citations[i + 1] - 1; // 현재 논문의 인용 횟수의 최솟값은 다음으로 큰 논문의 인용횟수다
        for(let j = c; j > to; j--){ 
            if(i + 1 === j) { // 내림차순이기 때문에 i + 1은 모두 j번이상 인용된 논문
                answer = j; // j번 이상 인용된 논문이 j개 있다면 
                break;
            }
        }
    }
    return answer;
}
