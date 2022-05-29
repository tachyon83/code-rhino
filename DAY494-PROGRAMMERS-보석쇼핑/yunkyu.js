function solution(gems) {
    let answer = [1, gems.length];
    const num = new Set(gems).size;
    
    // 투포인터
    let s = 0, e = 0;
    let minLength = gems.length;
 
    const map = new Map();
    map.set(gems[0], 1);
    while(e < gems.length) {
        if(map.size === num && e - s < minLength) { // map에 모든 보석이 있고 구간의 길이를 갱신가능할 때
            minLength = e - s;
            answer = [s + 1, e + 1];
        }
        
        if(map.size < num) { // map에 모든 보석이 없으면 보석을 하나씩 추가
            e++;
            if(map.has(gems[e])) {
                map.set(gems[e], map.get(gems[e]) + 1);
            }
            else{
                map.set(gems[e], 1);
            }
        }
        else { // map에 모든 종류의 보석이 있다면 가장 앞 제거
            if(map.get(gems[s]) === 1){ // 보석이 1개 있으면 map에서 삭제
                map.delete(gems[s]);
            } 
            else {
                map.set(gems[s], map.get(gems[s]) - 1); // 보석 수 1 감소
            }
            s++;
        }
    }

    return answer;
}
