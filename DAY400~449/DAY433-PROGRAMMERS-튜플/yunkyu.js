function solution(s) {
    const getRest = (curr,prev) => { // 현재 배열에서 이전 배열의 원소를 제거
        for(let i = 0; i < prev.length; i++){
            curr = curr.filter(a => a !== prev[i]);
        }
        
        return curr;
    };
    
    let answer = [];
    const splited = s.substring(1,s.length-1).split('},{'); // },{ 로 문자열 split
    let arr = [];
    splited.forEach((el) => { // split된 문자열에서 {,} 제거하고 배열로 변환
       arr.push(el.replace('{','').replace('}','').split(","));
    });
    arr.sort((a,b) => a.length - b.length); // 길이 오름차순으로 정렬
    
    answer.push(parseInt(arr[0][0])); 
    for(let i = 1; i < arr.length; i++){
        const rest = getRest(arr[i],arr[i - 1]);
        answer.push(parseInt(rest[0]));
    }
    
    return answer;
}
