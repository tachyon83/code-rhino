const fs = require('fs')
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')
const n = parseInt(input[0]),mod = parseInt(1e4) + 7
let dp1 = [],dp2 = []
for (let i = 0; i < 10; ++i) {
	dp1.push(1)
	dp2.push(0)
}
for (let i = 1; i < n; ++i) {
	for (let j = 0; j < 10; ++j) {
		for (let k = 0; k <= j; ++k) {
			dp2[j] = (dp2[j] + dp1[k]) % mod
		}
	}
	dp1 = JSON.parse(JSON.stringify(dp2))
	dp2 = new Array(10).fill(0)
}
console.log(dp1.reduce((a, b) => a + b, 0) % mod)
