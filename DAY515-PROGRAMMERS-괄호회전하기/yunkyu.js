function solution(s) {
    let answer = 0;
    const open = "[{(";
    const close = "]})";
    
    if(new Set(s).size === 1) return 0;
    
    const checkRight = (s) => {
        const stack = [];
        
        for(let i = 0; i < s.length; i++){
            if(open.indexOf(s[i]) !== -1){ // 열린 괄호면 stack에 삽입
                stack.push(s[i]);
            }
            else { // 닫힌 괄호일 때
                const closeIdx = close.indexOf(s[i]);
                if(stack[stack.length - 1] === open[closeIdx]) stack.pop(); // 닫는 괄호와 스택의 top이 열린 괄호로 한 쌍이라면 pop
                else return false;
            }
        }
        
        if(stack.length === 0) return true; // 스택이 비었으면 올바른 괄호 문자열
        else return false;
    }
    
    for(let i = 0; i < s.length; i++){
        if(i > 0) { 
            s = s.substr(1) + s[0]; // 괄호 회전
        }
        
        if(checkRight(s)) answer++; // 올바른 괄호 문자열 검사
    }
    
    return answer;
}
