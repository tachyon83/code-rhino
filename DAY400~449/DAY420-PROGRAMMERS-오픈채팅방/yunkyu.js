function solution(record) {
    let answer = [];
    const users = {};
    const logs = [];
    
    for(const r of record) {
        const splited = r.split(" "); // split으로 행동, 아이디, 닉네임을 추출
        const [action,id,nickname] = splited;
        if(!users[id]) users[id] = nickname; // 처음 들어온 유저라면 users에 저장
        if(action === 'Change'){ // 아이디 변경시
            users[id] = nickname;
        }
        else { // 들어오거나 나가거나
            if(action === 'Enter') { // 들어왔을시에 기존의 닉네임이 아니라면 변경
                if(users[id] !== nickname) users[id] = nickname;
            }
            logs.push([action,id]); // 로그에 행동과 아이디 저장
        }
    }
    
    for(const log of logs) { // 로그에 따라서 문자열 생성하여 answer에 삽입
        const [action,id] = log;
        const nickname = users[id];
        let str = `${nickname}님이 `
        str += action === 'Enter' ? '들어왔습니다.' : '나갔습니다.';
        answer.push(str);
    }
    return answer;
}
