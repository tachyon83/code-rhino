const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

var ln = 0, r, c, dr = [0, 1, 0, -1], dc = [1, 0, -1, 0], stack = []
var board = [], mx = 250, vis = [], sheep = 0, wolf = 0, a, b, flag
for (let i = 0; i < mx; ++i) {
    let temp = []
    for (let j = 0; j < mx; ++j)temp.push(0)
    vis.push(temp)
}

const repeat = (fn, v) => {
    return () => {
        if (!v) return
        return repeat(fn, fn(v))
    }
}

const exec = fn => {
    while (typeof fn == 'function') fn = fn()
}

const start = (fn, v) => {
    exec(function () {
        return repeat(fn, v)
    })
}

const dfs = arr => {
    [i, j, k] = arr
    for (let idx = k; idx < 4; ++idx) {
        let ni = i + dr[idx]
        let nj = j + dc[idx]
        if (0 <= ni && ni < r && 0 <= nj && nj < c) {
            if (board[ni][nj] != '#' && !vis[ni][nj]) {
                if (board[ni][nj] == 'o') a++
                else if (board[ni][nj] == 'v') b++
                vis[ni][nj] = 1
                stack.push([i, j, idx + 1])
                return [ni, nj, 0]
            }
        } else flag = 1
    }
}

const input = line => {
    if (!ln) [r, c] = line
        .split(' ')
        .map(e => parseInt(e))
    else board.push(line)
    ln++
}

const solve = _ => {
    for (let i = 0; i < r; ++i) {
        for (let j = 0; j < c; ++j) {
            if (board[i][j] != '#' && !vis[i][j]) {
                a = 0, b = 0, flag = 0
                vis[i][j] = 1
                if (board[i][j] == 'o') a++
                else if (board[i][j] == 'v') b++
                start(dfs, [i, j, 0])
                while (stack.length) start(dfs, stack.pop())
                if (!flag) {
                    if (a > b) b = 0
                    else a = 0
                    sheep += a
                    wolf += b
                }
            }
        }
    }
    console.log(sheep, wolf)
}

rl
    .on('line', input)
    .on('close', solve)
