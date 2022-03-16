function solution(s) {
    let answer = '';
    const word = ['zero','one','two','three','four','five','six','seven','eight','nine'];
    // 각 단어에 대해 정수를 mapping 하는 객체 생성
    const map = word.reduce((acc,curr,idx) => {
        acc[curr] = idx;
        return acc;
    },{});
    
    const arr = [];
    // 각 영단어가 문자열에 존재하는지 확인하고 index와 값을 배열에 저장
    for(key in map) {
        let start = 0;
        let idx = s.indexOf(key,start);
        while(idx !== -1) {
            arr.push([idx,map[key]]);
            idx = s.indexOf(key,idx + 1);
        }
    }
    
    // 0 or 숫자에 대해서 index와 값을 배열에 저장
    for(let i = 0; i < s.length; i++) {
        if(parseInt(s[i]) || s[i] === '0') arr.push([i,parseInt(s[i])])
    }
    arr.sort((a,b) => a[0] - b[0]); // index순으로 오름차순 정렬
    
    // 배열의 값을 합쳐 문자열을 만든다
    answer = arr.reduce((acc,curr) => {
        acc += curr[1].toString();
        return acc;
    },answer);
    
    return parseInt(answer);
}
