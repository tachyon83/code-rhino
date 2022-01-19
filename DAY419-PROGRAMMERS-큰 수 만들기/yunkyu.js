function solution(number, k) {
    let answer = '';
    const num = number.split("").map(n => parseInt(n));
    
    let idx = 0;
    for(let i = 0; i < number.length - k; i++) { // k의 개수를 제거했을때 길이 = number의 길이 - k
        let maxNum = num[idx];
        let maxIdx = idx;
        for(let j = idx; j <= i + k; j++) { // i ~ i + k &&  > maxIdx 
            if(maxNum < num[j]) { // 범위안의 가장 큰 수를 구한다
                maxNum = num[j];
                maxIdx = j;
            }
        }
        answer += maxNum;
        idx = maxIdx + 1;
    }
    return answer;
}
