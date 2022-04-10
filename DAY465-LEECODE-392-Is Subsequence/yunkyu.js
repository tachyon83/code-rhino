/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
const isSubsequence = function(s, t) {
    if(s === "") return true; // 빈 문자열일시 true
    let idx = 0;
    for(let i = 0; i < t.length; i++){
        if(s[idx] === t[i]) { // 동일한 문자 발견 시
            if(idx === s.length -1) return true; // Subsequence 발견
            idx++; // 다음 문자 탐색
        }
    }
    
    return false;
};
