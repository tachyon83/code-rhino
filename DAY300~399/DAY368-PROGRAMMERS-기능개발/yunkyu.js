function solution(progresses, speeds) {
    var answer = [];
    
    while(progresses.length !== 0) {
        for(let i =0; i<progresses.length; i++){
            if(progresses[i] < 100){ // 완성이 되지 않은 기능들 개발
                progresses[i] = (progresses[i] + speeds[i]) > 100 ? 100 : progresses[i] + speeds[i];
            }
        }
        
        if(progresses[0] === 100) { // 가장 앞에 있는 기능이 완성됐을때
            let cnt = 0;
            while(progresses[0] === 100){ // 개발이 덜 된 기능 이전까지 모두 배포
                progresses.shift();
                speeds.shift();
                cnt++;
            }
            
            answer.push(cnt);
        }
    }
    return answer;
}
