/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
const convert = function(s, numRows) {
    if(numRows === 1) return s;
    const str = new Array(numRows).fill(''); // zigzag 패턴을 row별로 나누어서 저장
    let depth = 0; 
    let dir = true; // true 일시 down, false 일시 up
    for(let i = 0; i < s.length; i++) {
        str[depth] += s[i]; // 
        if(dir && depth === numRows - 1) { // 아래로 향하고 있고 꺾어야할때
            dir = false;
        }
        if(!dir && depth === 0) { // 위로 향하고 있고 꺾어야할때
            dir = true;
        }
        
        if(dir) depth ++; // 아래로 향함
        else depth --; // 위로 향함
    }
    
    return str.reduce((acc,curr) => {
        acc += curr;
        return acc;
    },'');
};
