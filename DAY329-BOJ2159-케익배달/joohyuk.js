const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

const big = 200000 * 100000 + 1
let n = 0, suna = 0, orders = [], addr = [], dp = []
let dr = [0, 0, 1, 0, -1], dc = [0, 1, 0, -1, 0]
const dist = (c1, c2) => Math.abs(c1[0] - c2[0]) + Math.abs(c1[1] - c2[1])

const init = _ => {
    for (const order of orders) {
        let temp = []
        for (let i = 0; i < 5; ++i)temp.push([order[0] + dr[i], order[1] + dc[i]])
        addr.push(temp)
        dp.push(new Array(5).fill(big))
    }

    for (let i = 0; i < 5; ++i)dp[0][i] = dist(suna, addr[0][i])
}

const input = line => {
    if (!n) n = parseInt(line)
    else if (!suna) suna = line.split(' ').map(e => parseInt(e))
    else orders.push(line.split(' ').map(e => parseInt(e)))
}

const solve = _ => {
    init()
    for (let k = 1; k < orders.length; ++k) {
        for (let i = 0; i < 5; ++i) {
            for (let j = 0; j < 5; ++j) {
                dp[k][i] = Math.min(dp[k][i], dp[k - 1][j] + dist(addr[k][i], addr[k - 1][j]))
            }
        }
    }

    let ret = big
    for (const v of dp[orders.length - 1]) ret = Math.min(ret, v)
    console.log(ret)
}

rl
    .on('line', input)
    .on('close', solve)
