const menu = {}

// 메뉴 개수가 course개 일때 가능한 코스를 모두 찾아서 주문된 횟수를 구한다
const DFS = (idx, cnt, curr, order, course) => {
    if(cnt === course) {
        if(!menu[curr]) menu[curr] = 1; 
        else menu[curr]++;
        return;
    }
    
    for(let i = idx; i < order.length; i++){
        DFS(i + 1, cnt + 1, curr + order[i], order, course);
    }
}

function solution(orders, course) {
    var answer = [];
    
    // 각 order 문자열의 원소를 오름차순으로 변환
    for(let i = 0; i < orders.length; i++) {
        orders[i] = orders[i].split("").sort().join("");    
    }
    
    for(let i = 0; i < course.length; i++){
        const c = course[i]; // 각각 course 메뉴 개수에 따라
        for(let j = 0; j < orders.length; j++){ 
            DFS(0,0,'',orders[j],c)
        }
    }
    
    // 코스의 메뉴 개수에 따라 가장 많이 주문된 횟수 저장
    const maxCnt = new Array(11).fill(0);
    
    // 가장 많이 주문된 횟수를 구한다
    for(const m in menu) {
        if(menu[m] >= 2) {
            maxCnt[m.length] = Math.max(maxCnt[m.length],menu[m]);
        }
    }
    
    // 두번 이상 주문됐으며 가장 많이 주문된 코스를 찾는다
    for(const m in menu) {
        if(menu[m] >= 2 && maxCnt[m.length] === menu[m]) {
            answer.push(m);
        }
    }
    answer.sort();
    return answer;
}
