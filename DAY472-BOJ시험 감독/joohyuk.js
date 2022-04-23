const fs = require('fs')
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')

const n = parseInt(input[0], 0)
const ppl = input[1].split(' ').map(e => parseInt(e, 10))
const [ b, c ] = input[2].split(' ').map(e => parseInt(e, 10))

let ans = 0
ppl.forEach(e => {
  ans += parseInt(e / b, 10)
  const res = e % b
  ans += parseInt(res / c, 10)
  ans = res % c ? ans + 1 : 0 + ans
})
console.log(ans)
