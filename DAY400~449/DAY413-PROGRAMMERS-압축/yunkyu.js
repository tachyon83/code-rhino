function solution(msg) {
    let answer = [];
    const dict = {};
    let cnt = 26;
    // 사전에 A ~ Z 등록
    for(let i = 65; i <= 90; i++) {
        dict[String.fromCharCode(i)] = i - 64;
    }
    const msgLen = msg.length;
    
    for(let i = 0; i < msgLen;){ // msg의 첫번째 idx부터 끝까지
       for(let j = msgLen; j >= i; j--){ // i번째 idx부터 j번째 idx까지의 부분문자열을 구한다
           const substr = msg.substring(i,j);
           if(dict[substr]) { // 부분문자열이 사전에 존재한다면
               answer.push(dict[substr]);
               const newstr = msg.substring(i,j+1); // 다음 글자를 포함한 부분문자열을 사전에 등록
               dict[newstr] = ++cnt;
               i += substr.length; 
               break;
           }
       }
    }
    
    return answer;
}
