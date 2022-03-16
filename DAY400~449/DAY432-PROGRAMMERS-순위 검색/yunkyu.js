function solution(info, query) {
    let answer = [];
    const map = {};
    
    const combination = (infos,score,map,idx) => {
        let key = infos.join("");
        if(map[key]) { // map에 존재하면 해당 지원자의 점수를 추가해준다
            map[key].push(score);
        }else { // 존재하지 않으면 생성
            map[key] = [score];
        }
        
        // 지원서에 입력한 값에 해당 가능한 지원조건의 모든 조합을 구한다
        for(let i = idx; i < infos.length; i++){
            const arr = [...infos];
            arr[i] = '-';
            combination(arr,score,map,i + 1);
        }
    }
    
    const binarySearch = (arr,score) => {
        let start = 0 , end = arr.length - 1;
        while(start <= end) {
            const mid = Math.floor((start + end) / 2);

            if(arr[mid] >= score){
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return start;
    }
    
    for(const i of info) {
        const splited = i.split(" ");
        const score = Number(splited.pop());
        combination(splited,score,map,0);
    }
    
    for(const key in map) {
        map[key].sort((a,b) => a - b); // 이진 탐색을 위한 오름차순 정렬
    }

    for(const q of query) {
        const splitQuery = q.split(" ").filter((e) => e !== 'and');
        const score = parseInt(splitQuery.pop());
        
        const key = splitQuery.join("");
        if(map[key]) {
            const start = binarySearch(map[key],score); // 이진탐색을 이용해 현재 점수보다 같거나 큰 최소값의 idx를 구한다
            answer.push(map[key].length - start);
        }
        else { // 조건에 맞는 지원자가 존재하지 않으면
            answer.push(0);
        }
    }
    
    return answer;
}
