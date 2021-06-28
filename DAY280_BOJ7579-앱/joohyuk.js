const { mainModule } = require('process');
const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let ln = 0, memories, cost, n, m, dp = [], s = 0

const input = line => {
    if (!ln) [n, m] = line.split(' ').map(e => parseInt(e))
    else if (ln == 1) memories = line.split(' ').map(e => parseInt(e))
    else cost = line.split(' ').map(e => {
        e = parseInt(e)
        s += e
        return e
    })
    ln++
}

const solve = _ => {
    for (let i = 0; i < s + 1; ++i)dp.push(0)
    for (let i = 0; i < n; ++i) {
        for (let j = s; j >= 0; --j) {
            if (j >= cost[i]) dp[j] = Math.max(dp[j], dp[j - cost[i]] + memories[i])
        }
    }
    for (let i = 0; i < s + 1; ++i) {
        if (dp[i] >= m) {
            console.log(i)
            break
        }
    }
}

rl
    .on('line', input)
    .on('close', solve)
