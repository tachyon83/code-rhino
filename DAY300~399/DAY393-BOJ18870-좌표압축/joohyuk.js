const fs = require('fs')
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')

const conv = {}
const arr = input[1].split(' ').map(e => parseInt(e))
const arr2 = []
arr.forEach(e => arr2.push(e))
arr2.sort((a, b) => a - b)
let i = 0
arr2.forEach(e => {if (!(e in conv)) conv[e] = i++})
const ans = []
arr.forEach(e => ans.push(conv[e]))
console.log(ans)
