function solution(n, info) {
    let answer = [-1];
    const arr = new Array(11).fill(0);
    let maxDiff = 0;
    
    const compareSame = () => {
        for(let i = 10; i >= 0; i--){
            if(arr[i] > answer[i]) return true;
            else if(arr[i] < answer[i]) return false;
        }
    }
    
    const compareScore = () => {
        let apeach = 0, ryan = 0;
        for(let i = 0; i < 11; i++){
            if(info[i] === 0 && arr[i] === 0) continue; // 둘 다 k점에 화살을 맞히지 못한 경우
            if(info[i] >= arr[i]) apeach += 10 - i; // 같은 수 or 어피치가 더 많이 맞힌 경우 어피치가 점수 획득
            else ryan += 10 - i;
        }
    
        if(ryan > apeach) { // 라이언이 이겼을 때
            if(maxDiff === ryan - apeach && compareSame()) { // 가장 큰 점수차이와 동일할 때 가장 낮은 점수를 더 많이 맞힌 경우를 선택
                answer = [...arr];
            }
            if(maxDiff < ryan - apeach) { // 가장 큰 점수차이로 갱신
                maxDiff = ryan - apeach;
                answer = [...arr];
            }
        }
    }
    
    const DFS = (idx, rest) => {
        if(idx === 11) {
            if(rest > 0) arr[10] = rest; // 화살이 남아있다면 0점에 모두 쏜다
            compareScore();
            arr[10] = 0;
            return;
        }
        
        if(info[idx] < rest) { // 어피치가 맞춘 화살보다 현재 화살이 많다면
            // (어피치가 맞춘 화살 + 1) 만큼만 쏘면 점수 획득
            arr[idx] = info[idx] + 1;
            DFS(idx + 1, rest - info[idx] - 1);
            arr[idx] = 0;
        }
        DFS(idx + 1, rest); // 화살을 쏘지 않음
    }
    
    DFS(0, n);
    
    return answer;
}
