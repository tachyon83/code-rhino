const fs = require('fs')
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')

const n = parseInt(input[0])
const weights = input[1].split(' ').map(e => parseInt(e))
const balls = input[3].split(' ').map(e => parseInt(e))
const dp = [],big = 15000 + 1

for (let i = 0; i < n; ++i) {
	const temp = []
	for (let j = 0; j < big; ++j) temp.push(0)
	dp.push(temp)
}

dp[0][0] = 1
dp[0][weights[0]] = 1
for (let i = 1; i < n; ++i) {
	for (let j = 0; j < big; ++j) {
		if (dp[i - 1][j]) {
			dp[i][j] = 1
			dp[i][j + weights[i]] = 1
			dp[i][Math.abs(j - weights[i])] = 1
		}
	}
}

console.log(balls.map(ball => (dp[n - 1][ball] ? 'Y ' : 'N ')).join(''))
