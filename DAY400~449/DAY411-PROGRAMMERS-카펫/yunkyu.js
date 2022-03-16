function solution(brown, yellow) {
    let answer = [];
    
    for(let i = 1; i <= Math.sqrt(yellow); i++){
        if(yellow % i === 0) { // 노란색의 가로 세로 조합을 구한다
            if(i + yellow/i + 2 === brown / 2) { // 갈색카펫 개수의 반 = 노란색 가로 길이 + 세로길이 + 2
                answer.push(yellow/i + 2);
                answer.push(i + 2);
            }
        }
    }
    return answer;
}
