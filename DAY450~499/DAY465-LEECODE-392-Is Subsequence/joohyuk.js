/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isSubsequence = function(s, t) {
    if(s.length>t.length)return false
    let i=0,j=0
    while(j<t.length){
        if(t[j]===s[i])i++
        j++
    }
    return i===s.length
};
