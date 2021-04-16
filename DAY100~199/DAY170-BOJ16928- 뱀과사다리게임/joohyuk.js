const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let ln = 0, qs, n, m, a, b
var ladder = {}, snake = {}
let vis = [], q = [1], t = -1, curr, target = 100

const solve = _ => {
    while (q.length) {
        qs = q.length
        t++
        for (let i = 0; i < qs; ++i) {
            curr = q.shift()
            if (curr == target) {
                console.log(t)
                process.exit()
            }
            for (let j = 1; j <= 6; ++j) {
                if (curr + j <= target && !vis[curr + j]) {
                    vis[curr + j] = 1
                    let flag = 0
                    if (ladder[curr + j]) {
                        flag = 1
                        if (!vis[ladder[curr + j]]) {
                            vis[ladder[curr + j]] = 1
                            q.push(ladder[curr + j])
                        }
                    }
                    if (snake[curr + j]) {
                        flag = 1
                        if (!vis[snake[curr + j]]) {
                            vis[snake[curr + j]] = 1
                            q.push(snake[curr + j])
                        }
                    }
                    if (!flag) q.push(curr + j)
                }
            }
        }
    }
}

rl.on('line', function (line) {
    if (!ln) {
        [n, m] = line
            .split(' ')
            .map(e => parseInt(e))

        for (let i = 0; i < 100 + 1; ++i) vis.push(0)
        vis[1] = 1

    } else if (ln <= n) {
        [a, b] = line
            .split(' ')
            .map(e => parseInt(e))
        ladder[a] = b
    } else {
        [a, b] = line
            .split(' ')
            .map(e => parseInt(e))
        snake[a] = b
    }
    ln++
}).on('close', _ => {
    solve()
})
