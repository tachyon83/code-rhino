function solution(relation) {
    let answer = 0;
    
    const col_len = relation[0].length;
    const row_len = relation.length;
    let idxArr = [];
    // 비트마스크를 통해 모든 후보키 idx 조합 생성
    for(let i = 1; i <= (1 << col_len) - 1; i++){
        const idxs = [];
        for(let j = col_len - 1; j >= 0; j--){
            if(i & (1 << j)) idxs.push(j);
        }
        idxArr.push(idxs);
    }
    idxArr.sort((a,b) => a.length - b.length); // 후보키 구성 속성 개수 오름차순 정렬
    
    while(idxArr.length > 0){
        const idxs = idxArr.shift();
        const set = new Set();
        // 조합에 해당하는 속성값을 합쳐 set 자료구조에 삽입
        for(let j = 0; j < row_len; j++){
            let key = ""
            for(const idx of idxs) {
                key += relation[j][idx];
            }
            set.add(key);
        }
        if(set.size === row_len) { // set의 크기가 튜플의 총 개수와 같다면 유일성 만족
            answer++;
            idxArr = idxArr.filter((item) => !idxs.every((idx) => item.includes(idx))); // 유일성을 만족하는 후보키를 부분집합으로 가지고 있는 슈퍼키 제외 (최소성 만족)
        }
    }
    return answer;
}
