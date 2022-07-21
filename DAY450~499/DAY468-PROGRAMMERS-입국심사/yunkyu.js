function solution(n, times) {
    let answer;
    let min = 1e9 + 1, max = -1;
    // 심사 시간의 최대, 최소값을 구한다.
    for(let i = 0; i < times.length; i++){
        min = Math.min(min, times[i]);
        max = Math.max(max, times[i]);
    }
    let left = min, right = max * n; // 최대 => n명을 max의 심사시간을 가지는 심사관이 모두 심사할 때
    answer = right + 1;
    
    // 구간이 매우 크기 때문에 이분탐색
    while(left <= right) {
        const mid = Math.floor((left + right) / 2);
        let sum = 0;
        // mid 시간동안 심사할 수 있는 사람 수
        for(let i = 0; i < times.length; i++){
            sum += Math.floor(mid / times[i]);
        }
        
        if(sum >= n){ // mid 시간안에 최소n명을 심시할 수 있다면 
            answer = mid;
            right = mid - 1; // 시간을 줄인다.
        }else{ // mid 시간안에 최소n명을 심시할 수 없다면
            left = mid + 1; // 시간을 늘린다.
        }
    }
    
    return answer;
}
