const fs = require('fs')
let input=fs.readFileSync('/dev/stdin').toString().trim().split('\n')

const n = parseInt(input), teams = ['A', 'B']
const dp = []
for (let i = 0; i < 7; ++i) {
    const temp = []
    for (let j = 0; j < n; ++j)temp.push(0)
    dp.push(temp)
}

const dnc = (l, r, d, t) => {
    if (d === 7) return
    const mid = parseInt((l + r) / 2)
    for (let i = l; i < r; ++i) {
        if (i < mid) dp[d][i] = teams[t]
        else dp[d][i] = teams[(t + 1) % 2]
    }
    dnc(l, mid, d + 1, t)
    dnc(mid, r, d + 1, (t + 1) % 2)
}

dnc(0, n, 0, 0)
dp.forEach(day => console.log(day.join('')))
