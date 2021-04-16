const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let ln = 0, n, m, g = [], p, q

const input = line => {
    if (!ln) {
        [n, m] = line.split(' ').map(e => parseInt(e))
        for (let i = 0; i < n + 1; ++i) {
            let temp = []
            for (let j = 0; j < n + 1; ++j)temp.push(0)
            g.push(temp)
        }
    } else {
        [p, q] = line.split(' ').map(e => parseInt(e))
        g[p][q] = 1
    }
    ln++
}

const cnt = _ => {
    let ans = 0
    for (let i = 1; i < n + 1; ++i) {
        let flag = false
        for (let j = 1; j < n + 1; ++j) {
            if (i == j) continue
            if (!g[i][j] && !g[j][i]) {
                flag = true
                break
            }
        }
        if (!flag) ans++
    }
    return ans
}

const fw = _ => {
    for (let k = 1; k < n + 1; ++k) {
        for (let i = 1; i < n + 1; ++i) {
            if (i == k) continue
            for (let j = 1; j < n + 1; ++j) {
                if (j == i || j == k || !g[i][k] || !g[k][j]) continue
                g[i][j] = g[i][k] + g[k][j]
            }
        }
    }
    console.log(cnt())
}

rl
    .on('line', input)
    .on('close', fw)
