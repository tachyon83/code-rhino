const fs = require('fs')
let input
input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')

const n = parseInt(input[0])
const sessions = [],
	dp = []
for (let i = 1; i <= n; ++i) {
	sessions.push(input[i].split(' ').map(e => parseInt(e)))
	dp.push(0)
}
dp.push(0)

let mx = 0
for (let i = 0; i < n; ++i) {
	const [ t, w ] = sessions[i]
	dp[i] = Math.max(dp[i], mx)
	mx = dp[i]
	if (i + t <= n) dp[i + t] = Math.max(dp[i + t], dp[i] + w)
}
console.log(Math.max(dp[n], mx))
