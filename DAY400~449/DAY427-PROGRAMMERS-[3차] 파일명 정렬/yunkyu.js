function solution(files) {
    let answer = [];
    let arr = [];
    
    // 각 파일에 대한 HEAD, NUMBER를 알아낸다
    files.forEach((file) => {
        const regex1 = /\d+/; // 정수 1개 이상인 문자열
        const num = file.match(regex1); // 정규표현식으로 NUMBER 추출
        const regex2 = /[^0-9]+/; // 0~9가 아닌 문자 한개 이상인 문자열
        const head = file.match(regex2); // 정규표현식으로 HEAD 추출
        arr.push({
            name: file,
            head:head[0],
            num:Number(num[0]),
        })
    })
    
    arr.sort((a,b) => {
        if(a.head.toLowerCase() !== b.head.toLowerCase()){ // HEAD가 같지 않을 경우 HEAD 오름차순 정렬
            return a.head.toLowerCase() < b.head.toLowerCase() ? -1 : 1;
        }
        else return a.num - b.num; // HEAD가 같을 경우 NUMBER에 따른 오름차순 정렬
    })
    
    // answer에 정렬된 파일의 이름을 삽입
    answer = arr.reduce((acc,curr) => {
        acc.push(curr.name);
        return acc
    },answer)
    
    return answer;
}
