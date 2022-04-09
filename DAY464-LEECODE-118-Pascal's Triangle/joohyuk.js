/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function(numRows) {
    const ret=[]
    for(let i=0;i<numRows;++i)ret.push(generate2(ret[ret.length-1]))
    return ret
};

var generate2 = function(arr) {
    if(!arr)return [1]
    const ret=new Array(arr.length+1).fill(1)
    for(let i=0;i<arr.length-1;++i)ret[i+1]=arr[i]+arr[i+1]
    return ret
}
