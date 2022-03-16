function solution(id_list, report, k) {
    let answer = [];
    let map = {};
    // 사용자별 신고받은 횟수와 신고한 유저 리스트에 대해 초기화
    id_list.forEach((id) => {
        map[id] = {
            cnt:0,
            report:[],
        };        
    })
    
    // 사용자별 신고받은 횟수와 신고 리스트를 구한다.
    report.forEach((rp) => {
        const [user,report] = rp.split(" ");
        if(map[user].report.indexOf(report) === -1) {
            map[report].cnt++;
            map[user].report.push(report);
        }
    })
    
    // 유저별 신고 리스트 중 k번 이상으로 신고당한 유저의 수를 구함 
    id_list.forEach((id) => {
        let cnt = 0;
        map[id].report.forEach((rp) => {
            if(map[rp].cnt >= k) cnt++;
        })
        answer.push(cnt);
    })
    
    return answer;
}
