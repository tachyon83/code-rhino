const check = (a) => { // 영문자로 이루어져있는지 확인
    const code = a.charCodeAt();
    if(97 <= code && code <= 122) return true;
    return false;
}

function solution(str1, str2) {
    let answer = 0;
    // 대소문자 구분을 무시하기 위해 소문자로 치환
    const s1 = str1.toLowerCase(str1);
    const s2 = str2.toLowerCase(str2);
    
    const ms1 = {};
    const ms2 = {};
    
    // 각각 문자열에 대해 다중집합을 만든다
    for(let i = 0; i < s1.length - 1; i++){
        const sub = s1.substr(i,2);
        if(!check(sub[0]) || !check(sub[1])) continue; // 문자열이 영문자로만 돼있는지 확인
        
        if(!ms1[sub]) ms1[sub] = 1;
        else ms1[sub] ++;
    }
    for(let i = 0; i < s2.length - 1; i++){
        const sub = s2.substr(i,2);
         if(!check(sub[0]) || !check(sub[1])) continue;
        
        if(!ms2[sub]) ms2[sub] = 1;
        else ms2[sub] ++;
    }
    
    // 두 집합이 공집합일때
    if(Object.keys(ms1).length === 0 && Object.keys(ms2).length === 0) return 65536;
    
    let union = 0, inter = 0;
    for(const key in ms1) {
        const v1 = ms1[key], v2 = ms2[key];
        if(v2) { // 두 집합에 존재하는 값이면 
            union += Math.max(v1,v2); // 합집합은 더 큰값을 취한다
            inter += Math.min(v1,v2); // 교집합은 더 작은값을 취한다
            delete ms2[key]; // ms2에서 교집합 제외
        } // ms1에만 존재한다면 합집합에 추가
        else {
            union += v1;
        }
    }
    // ms2에만 존재하는 값에 대해 union 에 더해준다
    for(const key in ms2) {
        union += ms2[key];
    }
    
    answer = Math.floor((inter / union) * 65536);
    
    return answer;
}
