const fs = require('fs')
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')

const s1 = input[0]
const s2=input[1]
let o=new Array(s1.length+1).fill(0)
let n=new Array(s1.length+1).fill(0)

for(let i=0;i<s2.length;++i){
    for(let j=0;j<s1.length;++j){
        if(s2[i]===s1[j])n[j+1]=o[j]+1
        else n[j+1]=Math.max(o[j+1],n[j])
    }
    o=JSON.parse(JSON.stringify(n))
    n=new Array(s1.length+1).fill(0)
}
console.log(n[s1.length])
