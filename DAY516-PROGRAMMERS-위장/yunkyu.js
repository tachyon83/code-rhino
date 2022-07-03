function solution(clothes) {
    let answer = 0;
    const map = new Map();
    const keys = [];
    
    // 의상 종류별 개수를 map에 저장
    for(const [name, type] of clothes){
        if(!map.get(type)) map.set(type, 1);
        else map.set(type, map.get(type) + 1);
    }
    
    // 각 의상 종류마다 [의상 개수 + 1](입지 않는 경우까지 포함)가지의 경우의 수가 존재한다.
    for(const [key, value] of map) {
        keys.push(value + 1);
    }
    
    answer = keys.reduce((acc,curr) => {
        return acc * curr;
    },1)
    
    // 아무것도 입지않는 경우 제외
    answer -= 1;
    return answer;
}
