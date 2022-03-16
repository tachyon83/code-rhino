function solution(clothes) {
    let answer = 0;
    const obj = {};
    const keys = [];
    // clothes 종류별 구분
    clothes.forEach((c) => {
        if(!obj[c[1]]) obj[c[1]] = [c[0]];
        else obj[c[1]].push(c[0]);
    });
    for(const key in obj) { // 각 종류 가짓수 + 1 => 쓰지 않음 추가
        keys.push(obj[key].length + 1);
    }
    answer = keys.reduce((acc,curr) => {
        return acc * curr;
    },1)
    answer -= 1; // 모두 쓰지 않을 제외
    return answer;
}
