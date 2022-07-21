/**
 * @param {number} numRows
 * @return {number[][]}
 */
const generate = function(numRows) {
    const arr = [];
    for(let i = 0; i < numRows; i++){
        if(i === 0) arr.push([1]); // 첫번째 row면 1하나만 존재
        else { 
            const curr = [1]; 
            for(let j = 0; j < i - 1; j++){ // 이전 row에서서 합친 숫자들을 현재 row에 하나씩 push
                curr.push(arr[i-1][j] + arr[i-1][j+1]);
            }
            curr.push(1);
            arr.push(curr);
        }
    }
    return arr;
};
