class Node {
    constructor(value, prev) {
        this.value = value;
        this.prev = prev;
        this.next = null;
    }
}


function solution(n, k, cmd) {
    let answer = new Array(n).fill('O');
    const memo = [];
    
    let prev = new Node(0);
    let ptr;
    // 연결 리스트 생성
    for(let i = 1; i < n; i++){
        const node = new Node(i, prev);
        prev.next = node;
        prev = node;
        
        if(i === k) { // k번째 node 저장
            ptr = node;
        }
    }
    
    const moveUp = (cnt) => { // 연결 리스트 이전으로 이동
        for(let i = 0; i < cnt; i++){
            ptr = ptr.prev;
        }
    }
    const moveDown = (cnt) => { // 연결 리스트 다음으로 이동
        for(let i = 0; i < cnt; i++){
            ptr = ptr.next;
        }
    }
    const deleteNode = () => {
        const {value, prev, next} = ptr;
        memo.push(ptr); // 지운 행 저장
        ptr = next ? next : prev; // 마지막 행이면 이전 행을 가르킨다.
        if(prev) prev.next = next;
        if(next) next.prev = prev;
        answer[value] = 'X';
    }
    const recovery = () => {
        const node = memo.pop(); // 가장 최근에 지운 행
        const {value, prev, next} = node;
        if(prev) prev.next = node;
        if(next) next.prev = node;
        answer[value] = 'O';
    }
    
    cmd.forEach((line) => {
        const splited = line.split(" ");
        switch(splited[0]){
            case 'D': // 아래로 이동
                moveDown(parseInt(splited[1]))
                break;
            case 'U': // 위로 이동
                moveUp(parseInt(splited[1]))
                break;
            case 'C': // 삭제
                deleteNode();
                break;
            case 'Z': // 복구
                recovery();
                break;
            default:
        }
    })
    
    return answer.join('');
}
