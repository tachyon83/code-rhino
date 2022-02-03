function solution(m, musicinfos) {
    let answer = '';
    let maxTime = 0;
    
    for(const mi of musicinfos) {
        const splited = mi.split(',');
        // 시작시간과 끝난시간의 시와 분을 정수로 구한다.
        const start = splited[0].split(":").map(a=>parseInt(a)); 
        const end = splited[1].split(":").map(a=>parseInt(a));
        const spend = (end[0] - start[0]) * 60 + end[1] - start[1]; // 총 재생시간을 구함
        
        let i = 0 , str = '', s = spend;
        while(s > 0) { // 총 재생된 음악을 얻는다
            if(i > splited[3].length - 1) i = 0; // 끝까지 재생했다면 처음부터 다시 재생
            s--;
            str += splited[3][i];
            if(splited[3][i + 1] === '#') { // #이 붙는 음 처리
                str += '#';
                i += 2;
            }
            else i++;
        }
        
        let findIdx = str.indexOf(m);
        while(findIdx !== -1) { // 재생된 음악에서 멜로디가 없을때까지
            if(str[findIdx + m.length] !== '#') { // 멜로디 끝 index 다음에 #이 붙은 경우 처리
                if(maxTime < spend) { // 가장 긴 재생시간을 가진 음악을 찾는다
                    answer = splited[2];
                    maxTime = spend;
                    break;
                }
            }
            
            findIdx = str.indexOf(m, findIdx + 1);
        }
    }
    
    if(answer === '') answer = "(None)"; // 조건에 일치하는 음악이 없을때
    return answer;
}
