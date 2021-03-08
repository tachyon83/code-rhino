const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

var board = [], stack = []
let sz = 5, num = 6, di = [0, 1, 0, -1], dj = [-1, 0, 1, 0]
let s = new Set()

const repeat = (fn, v) => {
    return () => {
        if (!v) return
        return repeat(fn, fn(v))
    }
}

const checker = fn => {
    while (typeof fn == 'function') fn = fn()
}

const starter = (fn, v) => {
    checker(function () {
        return repeat(fn, v)
    })
}

const dfs = v => {
    [i, j, ii, st] = v
    if (st.length == num) {
        s.add(parseInt(st))
        return false
    }
    for (let idx = ii; idx < 4; ++idx) {
        let ni = i + di[idx], nj = j + dj[idx]
        if (0 <= ni && ni < sz && 0 <= nj && nj < sz) {
            if (idx < 3) stack.push([i, j, idx + 1, st])
            return [ni, nj, 0, st + board[ni][nj]]
        }
    }
}

const solve = _ => {
    for (let i = 0; i < sz; ++i) {
        for (let j = 0; j < sz; ++j) {
            starter(dfs, [i, j, 0, board[i][j]])
            while (stack.length) starter(dfs, stack.pop())
        }
    }
    console.log(s.size)
}

rl
    .on('line', function (line) { board.push(line.split(' ')) })
    .on('close', _ => { solve() })
