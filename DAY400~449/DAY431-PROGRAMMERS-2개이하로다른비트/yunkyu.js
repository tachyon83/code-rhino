function solution(numbers) {
    let answer = [];
    
    numbers.forEach((num) => {
        if(num % 2 === 0) { // 홀수일땐 가장 처음의 비트가 0이므로 0만 1로 바꾼 1을 더한값이 답
            answer.push(num + 1);
        }
        else { // 짝수일땐 뒤에서부터 0이 처음 나오는 비트를 1로 바꾸고 이전비트를 0으로 바꾼수가 답
            const bits = "0" + num.toString(2); // 1밖에 없는 경우도 있으므로 이진수로 변환한 수 앞에 0을 추가
            const firstZeroIdx = bits.lastIndexOf('0'); // 뒤에서부터 0이 처음나온 비트의 인덱스를 찾는다.
            answer.push(parseInt(bits.substring(0,firstZeroIdx) + "10" + bits.substring(firstZeroIdx + 2),2));
        }
    })
    
    return answer;
}
