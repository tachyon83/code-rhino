const fs = require('fs')
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')

const n = input[0]
let ans = 0
const dp = []
for (let i = 0; i < n; ++i) dp.push(0)
for (let i = 0; i < n; ++i) {
  const arr = input[i + 1].split(' ').map(e => parseInt(e))
  for (let j = 0; j < arr[1]; ++j) dp[i] = Math.max(dp[i], dp[arr[j + 2] - 1])
  dp[i] += arr[0]
  ans = Math.max(ans, dp[i])
}
console.log(ans)
