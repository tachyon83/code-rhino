const selected = new Array(1 << 8).fill(false); // 비트마스크로 매핑된 아이디 조합 표현

const check = (bi,ui) => { 
    if(bi.length !== ui.length) return false;
    
    for(let i = 0; i < bi.length; i++){
        if(bi[i] === '*') continue;
        if(bi[i] !== ui[i]) return false;
    }
    return true;
}

const dfs = (b_idx, user_id, banned_id, bitmask) => {
    if(b_idx === banned_id.length){ // 제재 아이디를 모두 골랐다면
        if(selected[bitmask]) return 0; // 이미 찾았던 조합
        selected[bitmask] = true;
        return 1;
    }
    
    let res = 0;
    const current = banned_id[b_idx];
    for(let i = 0 ; i < user_id.length; i++){
        if(bitmask & (1 << i)) continue; // 이미 고른 아이디
        if(check(current,user_id[i])){ // user_id에 banned_id가 매핑이 되는지 확인 
            bitmask = bitmask | (1 << i); // 아이디를 비트마스크에 추가
            res += dfs(b_idx + 1, user_id,banned_id,bitmask);
            bitmask = bitmask & ~(1 << i); // 아이디를 비트마스크에서 제거
        }
    } 
    
    return res;
}

function solution(user_id, banned_id) {
    let answer = 0;
    answer = dfs(0,user_id,banned_id,0);
    
    return answer;
}
