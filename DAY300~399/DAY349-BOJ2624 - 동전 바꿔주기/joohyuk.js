const fs = require('fs')
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')
const T = parseInt(input[0])
const dp = new Array(T + 1).fill(0)
dp[0] = 1
const k = parseInt(input[1])
let coins = []
for (let i = 0; i < k; ++i) coins.push(input[2 + i].split(' ').map(e => parseInt(e)))
for (const coin of coins) {
	const [ w, cnt ] = coin
	for (let i = T; i >= 0; --i) {
		for (let j = 1; j <= cnt; ++j) {
			if (i + w * j <= T) dp[i + w * j] += dp[i]
		}
	}
}
console.log(dp[T])
