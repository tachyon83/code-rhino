const { profile } = require('console');
const { mainModule } = require('process');
const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let n = 0, m, dp = []

const input = line => {
    if (!n) {
        [n, m] = line.split(' ').map(e => parseInt(e))
    } else {
        let temp = []
        for (let i = 0; i < m; ++i)temp.push(parseInt(line[i]))
        dp.push(temp)
    }
}

const solve = _ => {
    let ans = 0
    if (!(n == 1 || m == 1)) {
        for (let i = 1; i < n; ++i) {
            for (let j = 1; j < m; ++j) {
                if (!dp[i][j]) continue
                if (dp[i - 1][j] && dp[i][j - 1] && dp[i - 1][j - 1]) {
                    dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1
                }

            }
        }
    }
    dp.forEach(l => { l.forEach(e => { ans = Math.max(ans, e) }) })
    console.log(ans * ans)
}

rl
    .on('line', input)
    .on('close', solve)
