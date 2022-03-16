function solution(n) {
    let answer = '';
    const nums = [4, 1, 2];
    
    while(n > 0) {
        answer += nums[n % 3]; // 나머지에 따라 숫자 대입
        n = n % 3 === 0 ? n / 3 - 1 : Math.floor(n / 3); // 나머지가 0 이면 몫을 하나 감소시킨다
    }
    answer = answer.split("").reverse().join(""); // 문자열을 뒤집어준다
    return answer;
}
