const map = new Map();

const find = (n) => {
    if(!map.has(n)){
        map.set(n,n+1);
        return n;
    }
    const par = find(map.get(n));
    map.set(n,par+1);
    return par;
}

function solution(k, room_number) {
    const answer = [];
    for(let i = 0; i < room_number.length; i++){
        const cur = room_number[i];
        const next = find(cur);
        answer.push(next);
    }
    return answer;
}
