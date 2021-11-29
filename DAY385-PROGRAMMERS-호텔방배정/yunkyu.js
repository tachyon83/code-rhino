// 효율성 1번 제외 틀림
const map = new Map();

function solution(k, room_number) {
    var answer = [];
    for(let i = 1; i <= k; i++){
        map[i] = true;
    }
    
    for(let i = 0; i < room_number.length; i++){
        if(map[room_number[i]]){
            map[room_number[i]] = false;
            answer.push(room_number[i]);
        }
        else {
            for(let j = room_number[i]; j <= k; j++) {
                if(map[j]) {
                    answer.push(j);
                    map[j] = false;
                    break;
                }
            }
        }
    }
    return answer;
}
